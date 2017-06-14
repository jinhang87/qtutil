#include <QCoreApplication>
#include <QtCore/private/qringbuffer_p.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //测试环形缓冲区的写入和读取+++++++++++++++++++++++++++++++
    qDebug()<<QStringLiteral("测试环形缓冲区的写入和读取+++++++++++++++++++++++++++++++");
    //方法1
    QRingBuffer ringBuffer;
    ringBuffer.append("CSDN ",5);
    ringBuffer.append("blog ",5);
    QByteArray qba("http://blog.csdn.net/caoshangpa");
    ringBuffer.append(qba);
    QByteArray head=ringBuffer.read();
    QByteArray tail=ringBuffer.read();
    qDebug()<<head<<tail;
    //方法2
    ringBuffer.clear();
    ringBuffer.append("CSDN ",5);
    ringBuffer.append("blog ",5);
    ringBuffer.append(qba);
    char str[100]={'\0'};
    ringBuffer.read(str,100);
    qDebug()<<str;
    //测试在缓冲区头和尾添加字符+++++++++++++++++++++++++++++++
    qDebug()<<QStringLiteral("测试在缓冲区头和尾添加字符+++++++++++++++++++++++++++++++");
    ringBuffer.clear();
    ringBuffer.append("CSDN ",5);
    ringBuffer.append("blog ",5);
    ringBuffer.append(qba);
    //头
    ringBuffer.ungetChar('{');
    //尾
    ringBuffer.putChar('}');
    memset(str,0,100);
    ringBuffer.read(str,100);
    qDebug()<<str;
    //测试读取一行+++++++++++++++++++++++++++++++++++++++++++
    qDebug()<<QStringLiteral("测试读取一行+++++++++++++++++++++++++++++++++++++++++++");
    ringBuffer.clear();
    ringBuffer.append("CSDN ",5);
    ringBuffer.append("blog\n",5);
    ringBuffer.append(qba);
    memset(str,0,100);
    if(ringBuffer.canReadLine())
    ringBuffer.readLine(str,100);
    qDebug()<<str;
    //测试拷贝数据+++++++++++++++++++++++++++++++++++++++++++
    qDebug()<<QStringLiteral("测试拷贝数据+++++++++++++++++++++++++++++++++++++++++++");
    ringBuffer.clear();
    ringBuffer.append("CSDN ",5);
    ringBuffer.append("blog ",5);
    ringBuffer.append(qba);
    memset(str,0,100);
    ringBuffer.peek(str,10),
    qDebug()<<str;
    //证明peek只是拷贝数据
    memset(str,0,100);
    ringBuffer.read(str,100);
    qDebug()<<str;
    //测试释放指定长度缓冲区+++++++++++++++++++++++++++++++++++++++++++
    qDebug()<<QStringLiteral("测试释放指定长度缓冲区+++++++++++++++++++++++++++++++++++++++++++");
    ringBuffer.clear();
    ringBuffer.append("CSDN ",5);
    ringBuffer.append("blog ",5);
    ringBuffer.append(qba);
    memset(str,0,100);
    ringBuffer.skip(10),
    ringBuffer.read(str,100);
    qDebug()<<str;
    //测试申请指定长度缓冲区+++++++++++++++++++++++++++++++++++++++++++
#if 0
    qDebug()<<QStringLiteral("测试申请指定长度缓冲区+++++++++++++++++++++++++++++++++++++++++++");
    ringBuffer.clear();
    ringBuffer.reserve(100);
    qint64 lenToTail=0;
    char * pos=ringBuffer.readPointerAtPosition(10,lenToTail);
    char * test="CSDN blog http://blog.csdn.net/caoshangpa";
    memcpy(pos,test,strlen(test));
    ringBuffer.skip(10);
    ringBuffer.chop(100-10-strlen(test));
    qDebug()<<ringBuffer.read();
    qDebug()<<lenToTail;
#endif
    return a.exec();
}
