#include "audiobuffer.h"
#include <QSettings>

/*
 * Constructor
 */
AudioBuffer::AudioBuffer()
{
    frameCounter = 0;
    streamTimeStamp = 0.0;

    QSettings settings;
    unsigned int rawFormat = settings.value("audiostreamer/rtAudioFormat", (unsigned int)0x2).toUInt();
    rawBuffer = RawBufferFactory::createBuffer(rawFormat);
}

/*
 * Destructor
 */
AudioBuffer::~AudioBuffer()
{
    if( rawBuffer ) delete rawBuffer;
}

/*
 * Allocates 'ringBufferSize' length ringbuffers and 'hwBufferSize' length raw buffer for each given channel.
 */
bool AudioBuffer::allocate(unsigned int ringBufferSize, QVector<unsigned int> channels, unsigned int hwBufferSize, double value)
{
    unsigned int numOfRawChannels = 0;
    channels = RingBuffer::cleanChannels(channels);
    if( !channels.isEmpty() ) numOfRawChannels = channels.last() - channels.first() + 1;
    bool rawBufferSuccess = rawBuffer->allocate(hwBufferSize, numOfRawChannels, value);
    bool ringBufferSuccess = ringBuffer.allocate(ringBufferSize, channels, value);
    return rawBufferSuccess && ringBufferSuccess;
}

/*
 * Switch the used audio format type. Recreates and reallocates the rawBuffer.
 */
bool AudioBuffer::prepareRawBuffer(unsigned int format, unsigned int hwBufferLength)
{
    unsigned int bufferSize = ringBufferSize();
    QVector<unsigned int> channels = ringBuffer.channelIds;

    if( rawBuffer ) delete rawBuffer;
    rawBuffer = RawBufferFactory::createBuffer(format);

    return allocate(bufferSize, channels, hwBufferLength);
}

/*
 * Return number of channels for the raw- or ringbuffers.
 */
unsigned int AudioBuffer::numberOfChannels(bool raw)
{
    if( raw ) return rawBuffer->numberOfChannels;
    return ringBuffer.channelIds.size();
}

/*
 * Returns true if frame counter is higher than ring buffer size.
 */
bool AudioBuffer::isFilled()
{
    if( ringBufferSize() == 0 ) return false;
    return frameCounter / ringBufferSize() > 0;
}
