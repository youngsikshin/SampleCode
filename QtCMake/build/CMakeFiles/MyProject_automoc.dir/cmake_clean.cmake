FILE(REMOVE_RECURSE
  "MyProject_automoc.cpp"
  "MyProjectLib_automoc.cpp"
  "CMakeFiles/MyProject_automoc"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/MyProject_automoc.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
