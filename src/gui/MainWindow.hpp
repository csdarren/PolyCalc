#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

float handleCuratives(int i);
float calcResult(float ppWeight, float percentNCO, float targetStoic, float curativeEquivWt);
bool valueErrorHandling(float f1, float f2, float f3);

void MainWindow(ImGuiWindowFlags flags)
{
    static float ppWeight = 0.0f;
    static float targetStoic = 0.0f;
    static float percentNCO = 0.0f;
    static float curativeEquivWt = 133.5f;
    static float results = 0.0f;
    static std::string resultsError = "";
    static int curativeSelection = 0;
    const char *curativesLabels[] = {"MBOCA", "Curene 49", "Curene 89", "Curene 93", "Curene 100 XPF", "Curene 107", "Curene 110", "Curene 185", "Curene 243", "Curene 280", "Curene 3005", "1,4 Butanediol"};

    const ImVec2 ButtonSize = {100.0f, 50.0f};

    ImGui::Begin("Main Window", nullptr, flags);

    ImGui::PushItemWidth(250.0f);
    ImGui::Spacing();
    ImGui::Text("Prepolymer Weight");
    ImGui::InputFloat("##ppweight", &ppWeight, 0.0f, 0.0f, "%.2f");
    ImGui::Spacing();

    ImGui::Text("Target Stoic");
    ImGui::InputFloat("##targetStoic", &targetStoic, 0.0f, 0.0f, "%.2f");
    ImGui::Spacing();

    ImGui::Text("Percent NCO");
    ImGui::InputFloat("##percentNCO", &percentNCO, 0.0f, 0.0f, "%.2f");
    ImGui::Spacing();

    ImGui::Text("Curative Equiv. Wt.");
    if (ImGui::Combo("##curativeEquivWt", &curativeSelection, curativesLabels, IM_ARRAYSIZE(curativesLabels)))
    {
        curativeEquivWt = handleCuratives(curativeSelection);
    }
    ImGui::Spacing();

    static bool displayUnitHeader = false;
    if (ImGui::Button("Calculate", ButtonSize))
    {
        if (valueErrorHandling(ppWeight, targetStoic, percentNCO))
        {
            displayUnitHeader = true;
            results = calcResult(ppWeight, percentNCO, targetStoic, curativeEquivWt);
        }
        else
        {
            resultsError = "All values must be greater than zero";
            displayUnitHeader = false;
        }
    }
    ImGui::Spacing();

    if (displayUnitHeader)
    {
        ImGui::Text("The units of curative needed is:");
        ImGui::Spacing();
        ImGui::Text("%.2f", results);
        ImGui::SameLine();
        ImGui::Text("grams");
    }
    else
    {
        ImGui::Text(resultsError.c_str());
    }

    ImGui::PopItemWidth();

    ImGui::End();
}

float calcResult(float ppWeight, float percentNCO, float targetStoic, float curativeEquivWt)
{
    float nco = 4200 / percentNCO;
    float stoic = (curativeEquivWt * ppWeight) * targetStoic;

    return (stoic / nco) * 100 / 100;
}

bool valueErrorHandling(float f1, float f2, float f3)
{
    if (f1 > 0 && f2 > 0 && f3 > 0)
    {
        return true;
    }
    else
        return false;
}

float handleCuratives(int i)
{
    float curativeEquivWt = 0.0f;
    switch (i) // 12 curatives
    {
    case 0:
        curativeEquivWt = 133.5f;
        break;
    case 1:
        curativeEquivWt = 49.0f;
        break;
    case 2:
        curativeEquivWt = 89.0f;
        break;
    case 3:
        curativeEquivWt = 93.0f;
        break;
    case 4:
        curativeEquivWt = 115.0f;
        break;
    case 5:
        curativeEquivWt = 107.0f;
        break;
    case 6:
        curativeEquivWt = 110.0f;
        break;
    case 7:
        curativeEquivWt = 185.0f;
        break;
    case 8:
        curativeEquivWt = 243.0f;
        break;
    case 9:
        curativeEquivWt = 280.0f;
        break;
    case 10:
        curativeEquivWt = 280.0f;
        break;
    case 11:
        curativeEquivWt = 45.0f;
        break;
    default:
        curativeEquivWt = 0.0f;
    }
    return curativeEquivWt;
}

#endif