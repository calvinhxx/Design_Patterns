cd ./src
cmake . -B../build
cd ../build/
cmake --build .
cd ./Debug
./App.exe