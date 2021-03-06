#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <QVector>
#include "bufferdefaults.h"

class RingBuffer {
public:
    RingBuffer();
    ~RingBuffer();

    unsigned int ringBufferSize;
    QVector<unsigned int> channelIds;
    QVector<QVector<double> > bufferContainer;

    bool allocate(unsigned int size = bufferdefaults::ringBufferSize, QVector<unsigned int> channels = QVector<unsigned int>(), double value = 0.0);
    bool insert(QVector<double> *rawData, unsigned int numOfFrames, unsigned int rawChannelCount);

    bool rotateRingbuffers(unsigned int delta);
    static QVector<unsigned int> cleanChannels(QVector<unsigned int> channels);
};

#endif // RINGBUFFER_H
