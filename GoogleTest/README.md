
To build GoogleTest, go to the VS Developer Prompt and run 

```
cmake -S repo\googletest -G "Visual Studio 17 2022" -A Win32  -DGOOGLETEST_VERSION=1.18 -DBUILD_GMOCK=OFF "-DCMAKE_GENERATOR_INSTANCE=C:/Program Files/Microsoft Visual Studio/2022/Community,version=17.13.35828.75"
msbuild gtest.sln -t:Build "/p:Configuration=Release;Platform=win32"
msbuild gtest.sln -t:Build "/p:Configuration=Debug;Platform=win32"
```

The option -G  "Visual Studio ..." is essential because the option `-A` is specific to Visual Studio. If you run cmake without -G "Visual Studio ...", you can't specify the architecture. 


Pay attention to Runtime Library in C/C++ -> Code Generation.
