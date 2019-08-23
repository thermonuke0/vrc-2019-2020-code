#include "main.h"

lv_obj_t * autonLabel;

GUI::GUI(){
    tabview = lv_tabview_create(lv_scr_act(), NULL);
    lv_obj_align(tabview, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);

    tabAuton = lv_tabview_add_tab(tabview, "Auton Selection");
    tabDebug = lv_tabview_add_tab(tabview, "Debug Menu");

    guiHeader = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(guiHeader, "UI v0.1.0");
    lv_obj_align(guiHeader, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

    static const char * autonMap[] = {"RFRONT", "BFRONT", "\n", "RBACK", "BBACK", "\n", "NOAUTO", ""};

    autoBtnMatrix = lv_btnm_create(tabAuton, NULL);
    lv_btnm_set_map(autoBtnMatrix, autonMap);
    lv_btnm_set_action(autoBtnMatrix, autonSelect);

    static const char * debugMap[] = {""};

    debugBtnMatrix = lv_btnm_create(tabDebug, NULL);
    lv_btnm_set_map(debugBtnMatrix, debugMap);
    lv_btnm_set_action(debugBtnMatrix, debugSelect);

    autonLabel = lv_label_create(tabAuton, NULL);
    lv_label_set_text(autonLabel, "No Auton");
    lv_obj_align(autonLabel, NULL, LV_ALIGN_IN_TOP_RIGHT, 0,0);
}


lv_res_t GUI::autonSelect(lv_obj_t * btmn, const char * txt){
    if(txt == "RFRONT") {autonIdentifier = AUTON_REDFRONT;}
    else if(txt == "BFRONT") {autonIdentifier = AUTON_BLUEFRONT;}
    else if(txt == "RBACK") {autonIdentifier = AUTON_REDBACK;}
    else if(txt == "BBACK") {autonIdentifier = AUTON_BLUEBACK;}
    else{autonIdentifier = AUTON_NONE;}
    updateAutonDisplay();
    return LV_RES_OK;
}

void GUI::updateAutonDisplay(){
    switch(autonIdentifier){
        case AUTON_REDFRONT:
            lv_label_set_text(autonLabel, "Red Front");
            break;
        case AUTON_BLUEFRONT:
            lv_label_set_text(autonLabel, "Blue Front");
            break;    
        case AUTON_REDBACK:
            lv_label_set_text(autonLabel, "Red Back");
            break;
        case AUTON_BLUEBACK:
            lv_label_set_text(autonLabel, "Blue Back");
            break;  
        default:
            lv_label_set_text(autonLabel, "No Auton");
        }
        
}