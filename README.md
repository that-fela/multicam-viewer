# Multi Camera Viewer

This project is for a 360* birds-eye view camera system. It utlises serveral networked Cameras.

### Prequisites:
Boost
```
sudo apt update
sudo apt install -y libboost-all-dev
```

GStreamer, FFMPEG, and GTK.
```
sudo apt update
sudo apt install -y build-essential cmake git pkg-config libgtk-3-dev libavcodec-dev libavformat-dev libswscale-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-good1.0-dev
```

OpenCV
```
cd ~/Downloads
git clone https://github.com/opencv/opencv.git
cd opencv
git checkout 4.x
```
```
cd ..
git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib
git checkout 4.x
```
```
cd ../opencv
mkdir build && cd build

cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      -DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
      -DWITH_GSTREAMER=ON \
      -DWITH_FFMPEG=ON \
      -DWITH_GTK=ON \
      ..
```
Check that GStreamer, FFMPEG, and GTK are enabled by scrolling up in the CMake output.
```
make -j
```
```
sudo make install
```

### Build using CMake
```
mkdir build && cd build

cmake ..

make -j
```