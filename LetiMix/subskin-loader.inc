<?xml version="1.0" encoding="utf-8" ?>
<DUMMY>
    <!-- LOADING SUBSKIN (KUIML FILE) -->
    <KUIML_WIDGET id="controls_widget" src="" v_margin="5" v_align="top" />

    <!-- script to load subskin -->
    <SCRIPT requires="$script_gui_path$;controls_widget.innerKUIML;log_area.display;$script_input_params_count$;$script_output_params_count$" preprocess="true" src="LetiMix/subskin-script.cxx" />

    <!-- if we're in Plug-n-Script (not exported plugin) -->
    <IF condition="$SCRIPT_EDIT_MODE$">
        <!-- trigger to reload subgui on opening  -->
        <ACTION_TRIGGER event_id="window.loaded.value_changed" condition_formula="window.loaded==1" script="reloadSubSkin(); dsp.input1 = 0; " requires="dsp.input1" async="true" />

        <!-- action to reload script -->
        <ACTION id="ReloadScript" type="Script" name="Reload script" script="$reload_script$ = abs($reload_script$ - 1); reloadSubSkin();" />
        <!-- trigger reload on new script loaded (script changed) -->
        <ACTION_TRIGGER event_id="$script_file_path$.value_changed" script=" reloadSubSkin(); $reload_script$ = abs($reload_script$ - 1); " requires="$script_file_path$;$reload_script$" async="true" />

        <!-- action for full skin + script reloading -->
        <ACTION id="ReloadMainSkin" type="Script" name="Reload skin" script="$reload_script$ = 1; gui.zoom=gui.zoom-0.5; " requires="gui.zoom;$reload_script$"/>
    </IF>

    <!-- if we're in exported plugin -->
    <IF condition="!$SCRIPT_EDIT_MODE$">
        <!-- trigger to reload subgui on opening  -->
        <ACTION_TRIGGER event_id="window.loaded.value_changed" condition_formula="window.loaded==1" script="reloadSubSkin()" requires="" async="true" />
        <!-- in exported plugin there might be no easy way to reload script -->
        <ACTION id="ReloadScript" type="Script" name="---" script="bool no_reload_possible = true;" />
        <!-- action for full skin reloading -->
        <ACTION id="ReloadMainSkin" type="Script" name="Reload skin" script="gui.zoom=gui.zoom-0.5; " requires="gui.zoom"/>
    </IF>
    
    <!-- trigger to reload GUI back to previous zoom level on skin reload -->
    <ACTION_TRIGGER event_id="window.loaded.value_changed" condition_formula="(gui.zoom-floor(gui.zoom)>0.1)" script="gui.zoom=gui.zoom+0.5; " requires="gui.zoom"/>

</DUMMY>
