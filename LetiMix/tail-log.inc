<?xml version="1.0" encoding="utf-8" ?>
<DUMMY>
<!-- log -->
    <VAR id="COLOR_BG_A" value="#333333" />
    <VAR id="COLOR_BG_B" value="#444455" />
    <VAR id="script_status" value="dsp.private_output0" />
    <VAR id="script_status_string" value="dsp.output_string0" />

    <LAYER_STACK width="100%" text_color="#cccccc" id="log_area" display="false">
      <svg width="100%" height="22" viewBox='0 0 100 10'><linearGradient id="linear-gradient"><stop offset="0%" stop-color="$COLOR_BG_A$"/><stop offset="100%" stop-color="$COLOR_BG_B$"/></linearGradient><rect fill="url(#linear-gradient)" width="100%" height="100%"/></svg>
      <INVISIBLE_ACTION_BUTTON width="100%" height="100%" action="OpenLogFile" cursor="system::hand" id="open_log_button">
        <TOOLTIP text="Click to open full log"/>
      </INVISIBLE_ACTION_BUTTON>
      <ROW width="100%" spacing="5" h_margin="4" id="open_log_button_content">
        <IMAGE_PARAM_METER param_id="$script_status$" image="status16.png" image_scaling=".5" images_count="4"/>
        <TEXT string_id="$script_status_string$" flex="1" text_h_align="left"/>
      </ROW>
      <PARAM_LINK from="open_log_button.pushed" to="open_log_button_content.v_offset"/>
      <PARAM_LINK from="open_log_button.pushed" to="open_log_button_content.h_offset"/>
    </LAYER_STACK>

    <!-- show log only if unusual strings received -->
    <ACTION_TRIGGER event_id="$script_status_string$.value_changed" condition_formula="window.loaded == 1" script="string log_line = $script_status_string$; bool default_log_text = ((log_line.findFirst(&quot;Script successfully loaded&quot;) > -1) or (log_line.findFirst(&quot;Loading script file&quot;) > -1) or (log_line.findFirst(&quot;Loading native script file&quot;) > -1) or (log_line == &quot;&quot;)); if (!default_log_text) log_area.display = true;" requires="log_area.display;$script_status_string$" async="true" />
</DUMMY>
