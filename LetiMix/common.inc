<?xml version="1.0" encoding="utf-8" ?>
<DUMMY>

<!-- letimix common DEFINES -->
<DEFINE>
	<VAR base_type="VARIABLE" override="true" />
	<AT base_type="ACTION_TRIGGER" />
	<LS base_type="LAYER_STACK" width="100%" />
</DEFINE>

<!-- build time IF -->
<TEMPLATE id="IF" condition="0">
    <REPEAT count="($condition$)!=0" index_name="_if_index_">
        <TEMPLATE_INNER_CONTENT/>
    </REPEAT>
</TEMPLATE>

<!-- system type (Windows, Mac) detection tags -->
<!-- first convert _SYSTEM_TYPE_ to integer to use in IF formulas -->
<TEMPLATE id="SYSTEM_DETECTION" systype="$_SYSTEM_TYPE_$">
  <VAR id="SYS_Windows" value="1" override="true" />
  <VAR id="SYS_Mac" value="2" override="true" />
    <VAR id="SYS_NO" value="$SYS_$systype$$" />
</TEMPLATE>
<SYSTEM_DETECTION />
<TEMPLATE id="IF_WINDOWS">
  <IF condition="$SYS_NO$ == $SYS_Windows$"><TEMPLATE_INNER_CONTENT /></IF>
</TEMPLATE>
<TEMPLATE id="IF_MAC">
  <IF condition="$SYS_NO$ == $SYS_Mac$"><TEMPLATE_INNER_CONTENT /></IF>
</TEMPLATE>

<!-- depending on system type -->
<IF_WINDOWS>
  <VAR id="DEFAULT_EDITOR" value="notepad.exe"/>
  <VAR id="FILE_EXPLORER_APP_NAME" value="Explorer"/>
    <VAR id="FILE_EXPLORER_APP" value="explorer.exe"/>
</IF_WINDOWS>
<IF_MAC>
  <VAR id="DEFAULT_EDITOR" value="TextEdit"/>
  <VAR id="FILE_EXPLORER_APP_NAME" value="Finder"/>
  <VAR id="FILE_EXPLORER_APP" value="Finder"/>
</IF_MAC>

<!-- strings holding text editor files -->
<STRING id="edit_script_app" default="$DEFAULT_EDITOR$" exposed="true" />
<STRING id="edit_kuiml_app" default="$DEFAULT_EDITOR$" exposed="true" />
<STRING id="open_log_app" default="$DEFAULT_EDITOR$" exposed="true" />
<!-- when in Plug-N-Script trying to catch selected editors -->
<IF condition="$SCRIPT_EDIT_MODE$">
  <STRING_LINK from="global.edit_script_application" to="edit_script_app" enabled="true" />
  <STRING_LINK from="global.edit_kuiml_application" to="edit_kuiml_app" enabled="true" />
  <STRING_LINK from="global.open_log_application" to="open_log_app" enabled="true" />
</IF>

<!-- simple next N (increase N) -->
<TEMPLATE id="NEXT_N">
	<VAR id="N" formula="$N$+1" />
</TEMPLATE>

<!-- ###################################### -->
<!-- MAPPINGS (rewritten from mappings.inc) -->
<!-- ###################################### -->

<!-- extra input params exist when plugin is not exported -->
<VAR id="HAS_EXTRA_INPUT_PARAMS" formula="$SCRIPT_PARAMS_COUNT$!=($PLUGIN_INPUT_PARAMS_COUNT$-1)"/>

<!-- map input parameters -->
<VAR id="bypass" value="dsp.input0" />
<VAR id="N" value="1" />
<IF condition="$HAS_EXTRA_INPUT_PARAMS$">
  <VAR id="reload_script" value="dsp.input1" />
  <VAR id="show_levels" value="dsp.input2" />
	<VAR id="N" value="8" /> <!-- start from 7, when extra params exist -->
</IF>
<REPEAT count="$SCRIPT_PARAMS_COUNT$">
    <VAR id="script_input$index$" value="dsp.input$N$" /><NEXT_N />
</REPEAT>

<!-- map input strings -->
<STRING id="script_file_selection" value="dsp.input_string0" />
<VAR id="N" value="1" />
<REPEAT count="$SCRIPT_STRINGS_COUNT$">
	<VAR id="script_input_string$index$" value="dsp.input_string$N$" />
	<NEXT_N />
</REPEAT>

<!-- map private output params -->
<VAR id="script_status" value="dsp.private_output0" />
<VAR id="script_input_params_count" value="dsp.private_output1" />
<VAR id="script_output_params_count" value="dsp.private_output2" />
<VAR id="N" value="3" />
<REPEAT count="$SCRIPT_PARAMS_COUNT$" index_name="i">
    <VAR id="script_input_param$i$_min" value="dsp.private_output$N$" /><NEXT_N />
    <VAR id="script_input_param$i$_max" value="dsp.private_output$N$" /><NEXT_N />
    <VAR id="script_input_param$i$_default" value="dsp.private_output$N$" /><NEXT_N />
    <VAR id="script_input_param$i$_steps" value="dsp.private_output$N$" /><NEXT_N />
</REPEAT>
<REPEAT count="$SCRIPT_OUT_PARAMS_COUNT$">
    <VAR id="script_output_param$index$_min" value="dsp.private_output$N$" /><NEXT_N />
    <VAR id="script_output_param$index$_max" value="dsp.private_output$N$" /><NEXT_N />
    <VAR id="script_output_param$index$_default" value="dsp.private_output$N$" /><NEXT_N />
</REPEAT>
<REPEAT count="$PLUGIN_AUDIO_INPUTS_COUNT$" index_name="CH" start="1">
    <VAR id="input_level$CH$" value="dsp.private_output$N$" /><NEXT_N />
    <VAR id="input_hold_level$CH$" value="dsp.private_output$N$" /><NEXT_N />
</REPEAT>
<REPEAT count="$PLUGIN_AUDIO_OUTPUTS_COUNT$" index_name="CH" start="1">
    <VAR id="output_level$CH$" value="dsp.private_output$N$" /><NEXT_N />
    <VAR id="output_hold_level$CH$" value="dsp.private_output$N$" /><NEXT_N />
</REPEAT>
<VAR id="script_input_strings_count" value="dsp.private_output$N$" /><NEXT_N />
<VAR id="script_file_type" value="dsp.private_output$N$" /><NEXT_N />

<!-- map output params -->
<VAR id="N" value="0" />
<REPEAT count="$SCRIPT_OUT_PARAMS_COUNT$">
    <VAR id="script_output$index$" value="dsp.output$N$" /><NEXT_N />
</REPEAT>

<!-- map output strings -->
<VAR id="script_status_string" value="dsp.output_string0" />
<VAR id="script_name_string" value="dsp.output_string1" />
<VAR id="script_description_string" value="dsp.output_string2" />
<VAR id="script_author_string" value="dsp.output_string3" />
<VAR id="script_file_path" value="dsp.output_string4" />
<VAR id="log_file_path" value="dsp.output_string5" />
<VAR id="script_doc_path" value="dsp.output_string6" />
<VAR id="script_gui_path" value="dsp.output_string7" />
<VAR id="N" value="8" />
<REPEAT count="$SCRIPT_PARAMS_COUNT$">
    <VAR id="script_input_param$index$_name" value="dsp.output_string$N$"/><NEXT_N />
    <VAR id="script_input_param$index$_unit" value="dsp.output_string$N$"/><NEXT_N />
    <VAR id="script_input_param$index$_enum_values" value="dsp.output_string$N$"/><NEXT_N />
    <VAR id="script_input_param$index$_value_format" value="dsp.output_string$N$"/><NEXT_N />
</REPEAT>
<REPEAT count="$SCRIPT_OUT_PARAMS_COUNT$">
    <VAR id="script_output_param$index$_name" value="dsp.output_string$N$"/><NEXT_N />
    <VAR id="script_output_param$index$_unit" value="dsp.output_string$N$"/><NEXT_N />
    <VAR id="script_output_param$index$_enum_values" value="dsp.output_string$N$"/><NEXT_N />
    <VAR id="script_output_param$index$_value_format" value="dsp.output_string$N$"/><NEXT_N />
</REPEAT>
<REPEAT count="$SCRIPT_STRINGS_COUNT$">
    <VAR id="script_input_string$index$_name" value="dsp.output_string$N$"/><NEXT_N />
</REPEAT>

<!-- Opacity -->
<PARAM id="global_opacity" min="0" max="100" default="100" unit="%" persistent="true"/>
<PARAM_LINK from="global_opacity" to="window.opacity" normalized="true"/>

<!-- Main audio bus channels-->
<FORMULA_PARAM id="main_bus_channels_count" formula="min(dsp.connected_inputs_count,dsp.connected_outputs_count)"/>

<!-- Custom parameters, built from param details in current script -->
<REPEAT count="$SCRIPT_PARAMS_COUNT$">
  <!-- Input param for display and control, linked to actual DSP param-->
  <PARAM id="custom_param$index$" min="0" max="1" default="0" name="Param $index$"/>
  <PARAM_LINK from="$script_input_param$index$_min$" to="custom_param$index$.min"/>
  <PARAM_LINK from="$script_input_param$index$_max$" to="custom_param$index$.max"/>
  <PARAM_LINK from="$script_input_param$index$_default$" to="custom_param$index$.default"/>
  <STRING_LINK from="$script_input_param$index$_unit$" to="custom_param$index$.unit"/>
  <STRING_LINK from="$script_input_param$index$_name$" to="custom_param$index$.name"/>
  <STRING_LINK from="$script_input_param$index$_value_format$" to="custom_param$index$.value_format"/>
  <STRING_LINK from="$script_input_param$index$_enum_values$" to="custom_param$index$.enum_values"/>

  <PARAM_LINK from="$script_input$index$$" to="custom_param$index$" normalized="true" enabled="true"/>
  <PARAM_LINK from="custom_param$index$" to="$script_input$index$$" enabled="false" id="link$index$" normalized="true"/>
  <PARAM_LINK from="custom_param$index$.capturing" to="link$index$.enabled"/>
</REPEAT>

<REPEAT count="$SCRIPT_OUT_PARAMS_COUNT$">
  <!-- Output param for display, linked to actual DSP param-->
  <PARAM id="custom_out_param$index$" min="0" max="1" default="0" name="Out Param $index$"/>
  <PARAM_LINK from="$script_output_param$index$_min$" to="custom_out_param$index$.min"/>
  <PARAM_LINK from="$script_output_param$index$_max$" to="custom_out_param$index$.max"/>
  <PARAM_LINK from="$script_output_param$index$_default$" to="custom_out_param$index$.default"/>
  <STRING_LINK from="$script_output_param$index$_unit$" to="custom_out_param$index$.unit"/>
  <STRING_LINK from="$script_output_param$index$_name$" to="custom_out_param$index$.name"/>
  <STRING_LINK from="$script_output_param$index$_value_format$" to="custom_out_param$index$.value_format"/>
  <STRING_LINK from="$script_output_param$index$_enum_values$" to="custom_out_param$index$.enum_values"/>
  <PARAM_LINK from="$script_output$index$$" to="custom_out_param$index$" normalized="true"/>
</REPEAT>

<!-- editable mode: make sure DSP data is not stripped (not exposing all to improve performance)-->
<IF condition="$SCRIPT_EDIT_MODE$">
  <REQUIRED_OBJECTS object_ids="dsp.sample_rate"/>
  <REPEAT count="$SCRIPT_PARAMS_COUNT$">
    <REQUIRED_OBJECTS object_ids="custom_param$index$.value_changed"/>
  </REPEAT>
  <REPEAT count="$SCRIPT_OUT_PARAMS_COUNT$">
    <REQUIRED_OBJECTS object_ids="custom_out_param$index$.value_changed"/>
  </REPEAT>
  <REPEAT count="$PLUGIN_INPUT_PARAMS_COUNT$">
    <REQUIRED_OBJECTS object_ids="dsp.input$index$;dsp.input$index$.value_changed;Show_dsp.input$index$_ControlSetup"/>
  </REPEAT>
  <REPEAT count="$PLUGIN_INPUT_STRINGS_COUNT$">
    <REQUIRED_OBJECTS object_ids="dsp.input_string$index$;dsp.input_string$index$.value_changed"/>
  </REPEAT>
  <REPEAT count="$PLUGIN_OUTPUT_PARAMS_COUNT$">
    <REQUIRED_OBJECTS object_ids="dsp.output$index$;dsp.output$index$.value_changed;Show_dsp.output$index$_ControlSetup"/>
  </REPEAT>
  <REPEAT count="$PLUGIN_PRIVATE_OUTPUT_PARAMS_COUNT$">
    <REQUIRED_OBJECTS object_ids="dsp.private_output$index$;dsp.private_output$index$.value_changed"/>
  </REPEAT>
  <REPEAT count="$PLUGIN_OUTPUT_STRINGS_COUNT$">
    <REQUIRED_OBJECTS object_ids="dsp.output_string$index$;dsp.output_string$index$.value_changed"/>
  </REPEAT>
</IF>

<!-- for compliance with default skin -->
<PARAM id="theme.show_settings" type="boolean" default="0" persistent="true" locked="false"/>
</DUMMY>