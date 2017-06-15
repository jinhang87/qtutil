#include <QCoreApplication>
#include <QWaitCondition>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QTime>

const int DataSize = 40;
const int BufferSize = 32;
char m_buffer[BufferSize];
int m_numBytes = 0;

QWaitCondition m_bufferNotEmtpy;
QWaitCondition m_bufferNotFull;
QMutex m_mutex;

class Producer : public QThread
{
public :
    void run() override
    {
        int i = 0;
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

        for(i = 0; i < DataSize; i++){
            m_mutex.lock();
            if(BufferSize == m_numBytes)
                m_bufferNotFull.wait(&m_mutex);
            m_mutex.unlock();

            m_buffer[i % BufferSize] = "ACGT"[(int)qrand()%4];
            printf("[%c]", m_buffer[i % BufferSize]);

            m_mutex.lock();
            ++m_numBytes;
            m_bufferNotEmtpy.wakeAll();
            m_mutex.unlock();
        }
    }
};


class Consumer : public QThread
{
public:
    void run() override
    {
        int i = 0;
        for(i = 0; i < DataSize ; i++){
            m_mutex.lock();
            if(0 == m_numBytes)
                m_bufferNotEmtpy.wait(&m_mutex);
            m_mutex.unlock();

            printf("<%c>", m_buffer[i % BufferSize]);

            m_mutex.lock();
            --m_numBytes;
            m_bufferNotFull.wakeAll();
            m_mutex.unlock();
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
