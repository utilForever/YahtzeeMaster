# YahtzeeMaster

<img src="./Medias/Logos/Logo.png" width=256 height=256 />

[![License](https://img.shields.io/badge/Licence-MIT-blue.svg)](https://github.com/utilForever/YahtzeeMaster/blob/master/LICENSE) [![Build Status](https://travis-ci.com/utilForever/YahtzeeMaster.svg?branch=master)](https://travis-ci.org/utilForever/YahtzeeMaster/branches) [![Build status](https://ci.appveyor.com/api/projects/status/github/utilForever/YahtzeeMaster?branch=master&svg=true)](https://ci.appveyor.com/project/utilForever/YahtzeeMaster/branch/master) [![Build Status](https://utilforever.visualstudio.com/YahtzeeMaster/_apis/build/status/utilForever.YahtzeeMaster?branchName=master)](https://utilforever.visualstudio.com/YahtzeeMaster/_build/latest?definitionId=16&branchName=master)

[![codecov](https://codecov.io/gh/utilForever/YahtzeeMaster/branch/master/graph/badge.svg)](https://codecov.io/gh/utilForever/YahtzeeMaster)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/e517597fbd0042bcb214fb8586fd74e4)](https://www.codacy.com/manual/utilForever/YahtzeeMaster?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=utilForever/YahtzeeMaster&amp;utm_campaign=Badge_Grade)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/utilForever/YahtzeeMaster.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/utilForever/YahtzeeMaster/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/utilForever/YahtzeeMaster.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/utilForever/YahtzeeMaster/context:cpp)
[![CodeFactor](https://www.codefactor.io/repository/github/utilforever/YahtzeeMaster/badge)](https://www.codefactor.io/repository/github/utilforever/YahtzeeMaster)

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=YahtzeeMaster&metric=alert_status)](https://sonarcloud.io/dashboard?id=YahtzeeMaster) [![Lines of Code](https://sonarcloud.io/api/project_badges/measure?project=YahtzeeMaster&metric=ncloc)](https://sonarcloud.io/dashboard?id=YahtzeeMaster) [![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=YahtzeeMaster&metric=sqale_rating)](https://sonarcloud.io/dashboard?id=YahtzeeMaster) [![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=YahtzeeMaster&metric=reliability_rating)](https://sonarcloud.io/dashboard?id=YahtzeeMaster) [![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=YahtzeeMaster&metric=security_rating)](https://sonarcloud.io/dashboard?id=YahtzeeMaster)

YahtzeeMaster is Yahtzee simulator using C++ with some reinforcement learning. The code is built on C++17 and can be compiled with commonly available compilers such as g++, clang++, or Microsoft Visual Studio. YahtzeeMaster currently supports macOS (10.14 or later), Ubuntu (18.04 or later), Windows (Visual Studio 2017 or later), and Windows Subsystem for Linux (WSL). Other untested platforms that support C++17 also should be able to build YahtzeeMaster.

## Key Features

  * C++17 based Yahtzee game library
  * Console and GUI simulator program
  * C++ and Python API

## Quick Start

You will need CMake to build the code. If you're using Windows, you need Visual Studio 2017 in addition to CMake.

First, clone the code:

```
git clone https://github.com/utilForever/YahtzeeMaster.git --recursive
cd YahtzeeMaster
```

### C++ API

For macOS or Linux or Windows Subsystem for Linux (WSL):

```
mkdir build
cd build
cmake ..
make
```

For Windows:

```
mkdir build
cd build
cmake .. -G"Visual Studio 15 2017 Win64"
MSBuild YahtzeeMaster.sln /p:Configuration=Release
```

### Docker

```
docker pull utilforever/yahtzeemaster:latest
```

## Documentation

TBA

## How To Contribute

Contributions are always welcome, either reporting issues/bugs or forking the repository and then issuing pull requests when you have completed some additional coding that you feel will be beneficial to the main project. If you are interested in contributing in a more dedicated capacity, then please contact me.

## Contact

You can contact me via e-mail (utilForever at gmail.com). I am always happy to answer questions or help with any issues you might have, and please be sure to share any additional work or your creations with me, I love seeing what other people are making.

## License

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The class is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2020 [Chris Ohk](http://www.github.com/utilForever).

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.