::
:: The ^ (caret) forces the next parameter to CLI command on a new line for readability.
:: Note the extra   (space) at the beginning of each new line to separate parameters when combined into one line during execution.
::
xcopy^
 "%SHADERDIR%\*.glsl" "%RELEASEDIR%\shaders" /Y /I
clang-cl^
 -static^
 /DNDEBUG^
 /D _CRT_SECURE_NO_WARNINGS^
 /MT^
 /O2^
 /Oi^
 /Gy^
 /permissive^
 /EHsc^
 /W3^
 /I "%CD%/"^
 /I "%CD%/ext/"^
 /Fe:"%CD%/x64/RELEASE/"^
 %CD%/main.cpp^
 %CD%/ext/GLAD/glad.c^
 %IMGUIDOCK%/imgui.cpp^
 %IMGUIDOCK%/imgui_draw.cpp^
 %IMGUIDOCK%/imgui_tables.cpp^
 %IMGUIDOCK%/imgui_widgets.cpp^
 %IMGUIDOCK%/imgui_impl_glfw.cpp^
 %IMGUIDOCK%/imgui_impl_opengl3.cpp^
 /link^
 /opt:ref^
 /subsystem:windows^
 shell32.lib^
 kernel32.lib^
 gdi32.lib^
 user32.lib^
 opengl32.lib^
 "%GLFW%/glfw3_mt.lib"^
