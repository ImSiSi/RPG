#!/bin/bash

# ✅ 你要編譯的原始 C++ 檔案
SOURCE_FILE="Game.cpp DBHelper.cpp"

# ✅ 編譯出來的執行檔名稱
OUTPUT_FILE="Game.out"

# ✅ MySQL Connector C++ 的 include 路徑（放頭文件 .h）
INCLUDE_PATH="/usr/local/mysql-connector-c++-9.3.0/include"

# ✅ MySQL Connector C++ 的 library 路徑（放 .dylib、.a）
LIB_PATH="/usr/local/mysql-connector-c++-9.3.0/lib64"

# ✅ 執行時告訴系統從哪裡找 .dylib（動態連結庫）
DYLIB_PATH="/usr/local/mysql-connector-c++-9.3.0/lib64:/opt/homebrew/opt/openssl@3/lib"

echo "🔧 編譯中..."

# ✅ clang++ 編譯指令
clang++ $SOURCE_FILE \
  -std=c++17 \
  -I$INCLUDE_PATH \
  -L$LIB_PATH \
  -lmysqlcppconnx \
  -Wl,-rpath,$LIB_PATH -Wl,-rpath,/opt/homebrew/opt/openssl@3/lib \
  -o $OUTPUT_FILE\

# ✅ 判斷編譯是否成功（$? 是上一個指令的 return code）
if [ $? -eq 0 ]; then
  echo "✅ 編譯成功，執行中..."
  DYLD_LIBRARY_PATH=$DYLIB_PATH ./$OUTPUT_FILE   # 設定 lib 路徑並執行
else
  echo "❌ 編譯失敗"
fi