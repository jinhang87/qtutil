#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <QTime>

const int DataSize = 40;
const int BufferSize = 32;
char m_buffer[BufferSize];
int m_numBytes = 0;

QSemaphore m_freeBytes(BufferSize);
QSemaphore m_usedBytes;

class Producer : public QThread
{
public :
    void run() override
    {
        int i = 0;
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        for(i = 0; i < DataSize; i++){
            m_freeBytes.acquire();
            m_buffer[i % BufferSize] = "ACGT"[(int)qrand() % 4];
            printf("[%c]", m_buffer[i % BufferSize]);
            m_usedBytes.release();
        }
    }
};


class Consumer : public QThread
{
public:
    void run() override
    {
        int i = 0;
        for(i = 0; i < DataSize; i++){
            m_usedBytes.acquire();
            printf("<%c>", m_buffer[i % BufferSize]);
            m_freeBytes.release();
            QThread::sleep(1);
        }
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();

    return a.exec();
}
