FILE(REMOVE_RECURSE
  "MyProject_automoc.cpp"
  "MyProjectLib_automoc.cpp"
  "CMakeFiles/MyProjectLib_automoc"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/MyProjectLib_automoc.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
