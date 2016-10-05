FILE(REMOVE_RECURSE
  "MyProject_automoc.cpp"
  "MyProjectLib_automoc.cpp"
  "moc_qtcmakesample.cpp"
  "ui_qtcmakesample.h"
  "CMakeFiles/MyProjectLib.dir/main.cpp.o"
  "CMakeFiles/MyProjectLib.dir/moc_qtcmakesample.cpp.o"
  "CMakeFiles/MyProjectLib.dir/MyProjectLib_automoc.cpp.o"
  "libMyProjectLib.pdb"
  "libMyProjectLib.so"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/MyProjectLib.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
