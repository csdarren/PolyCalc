::
:: The ^ (carret) forces next parameter to CLI command on a new-line for readability.
:: Note the extra   (space) at the beginning of each new-line to separate parameters when combined into one line during execution.
::
xcopy^
 "%SHADERDIR%\*.glsl" "%DEBUGDIR%\shaders" /Y /I
clang-cl^
 -static^
 /D _DEBUG^
 /D _CRT_SECURE_NO_WARNINGS^
 /std:c++20^
 /MP^
 /MDd^
 /O2^
 /Oi^
 /GL^
 /Gy^
 /permissive^
 /EHsc^
 /W0^
 /I "%CD%/"^
 /I "%CD%/ext/"^
 /Fe:"%CD%/x64/DEBUG/"^
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
 /subsystem:console^
 shell32.lib^
 kernel32.lib^
 gdi32.lib^
 user32.lib^
 opengl32.lib^
 "%GLFW%/glfw3.lib"^