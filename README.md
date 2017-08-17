# RtAudioStreamer

[![GitLab license](https://img.shields.io/badge/license-MIT-blue.svg)](https://gitlab.com/mxklb/rtaudiostreamer/blob/master/LICENSE)
[![Build Status](https://travis-ci.org/mxklb/rtaudiostreamer.svg?branch=master)](https://travis-ci.org/mxklb/rtaudiostreamer)
[![codecov](https://codecov.io/gh/mxklb/rtaudiostreamer/branch/master/graph/badge.svg)](https://codecov.io/gh/mxklb/rtaudiostreamer)
[![build status](https://gitlab.com/mxklb/rtaudiostreamer/badges/master/build.svg)](https://gitlab.com/mxklb/rtaudiostreamer/pipelines)
[![coverage report](https://gitlab.com/mxklb/rtaudiostreamer/badges/master/coverage.svg)](https://gitlab.com/mxklb/rtaudiostreamer/-/jobs)
[![codecov](https://codecov.io/gl/mxklb/rtaudiostreamer/branch/master/graph/badge.svg?token=orhkNtd8NC)](https://codecov.io/gl/mxklb/rtaudiostreamer)

This is a Qt C++ app which uses RtAudio API to process real time audio streams from connected audio hardware. This is an example project how to use RtAudioAPI for multi OS audio / soundcard monitoring.

## Build Dependencies
To succesfully build on Ubuntu (trusty):

    sudo apt-get install qt5-default qt5-qmake catch gdb librtaudio-dev

To succesfully build on OSX:

    brew update
    brew install qt5 rt-audio
    export PATH=$(brew --prefix)/opt/qt5/bin:$PATH

## Build Instructions

    qmake
    make
