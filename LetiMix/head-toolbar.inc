<?xml version="1.0" encoding="utf-8" ?>
<!-- TOP ROW (MENU AND TITLE) -->
    <LAYER_STACK width="100%">

      <!-- menu background -->
      <VAR id="COLOR_BG_A" value="#333333" />
      <VAR id="COLOR_BG_B" value="#444455" />
      <svg width="100%" height="23" viewBox='0 0 100 10'>
        <linearGradient id="linear-gradient"><stop offset="0%" stop-color="$COLOR_BG_A$"/><stop offset="100%" stop-color="$COLOR_BG_B$"/></linearGradient><rect fill="url(#linear-gradient)" width="100%" height="100%"/>
      </svg>

      <!-- menu contents -->
      <ROW v_margin="0" v_offset="0" text_color="#FFFFFF" width="100%">

        <LAYER_STACK width="100%" v_offset="0">
          <!-- menu left side icons -->
          <ROW spacing="4" h_align="left" h_offset="6">

            <!-- open menu icon -->
            <LAYER_STACK>
              <svg h_offset="2" width="16" height="16" id="Layer_1" viewBox="0 0 80 40">
                <line class="cls-1" x1="0" y1="10" x2="60" y2="10" stroke="white" stroke-width="5" /><line class="cls-1" x1="0" y1="20" x2="60" y2="20" stroke="white" stroke-width="5" /><line class="cls-1" x1="0" y1="30" x2="60" y2="30" stroke="white" stroke-width="5" />
              </svg>
              <INVISIBLE_ACTION_BUTTON action="OpenMenu" width="100%" height="100%" cursor="system::hand">
                <TOOLTIP text="Open Menu"/>
              </INVISIBLE_ACTION_BUTTON>
            </LAYER_STACK>

            <!-- zoom icon -->
            <LAYER_STACK>
              <svg width="16" height="16" viewBox="-55 -55 420 420">
                <path d="M273.587,214.965c49.11-49.111,49.109-129.021,0-178.132c-49.111-49.111-129.02-49.111-178.13,0
                  C53.793,78.497,47.483,140.462,76.51,188.85c0,0,2.085,3.498-0.731,6.312c-16.065,16.064-64.263,64.263-64.263,64.263
                  c-12.791,12.79-15.836,30.675-4.493,42.02l1.953,1.951c11.343,11.345,29.229,8.301,42.019-4.49c0,0,48.096-48.097,64.128-64.128
                  c2.951-2.951,6.448-0.866,6.448-0.866C169.958,262.938,231.923,256.629,273.587,214.965z M118.711,191.71
                  c-36.288-36.288-36.287-95.332,0.001-131.62c36.288-36.287,95.332-36.288,131.619,0c36.288,36.287,36.288,95.332,0,131.62
                  C214.043,227.996,155,227.996,118.711,191.71z" stroke="#AAAAAA" fill="#FFFFFF"/>
                <path d="M126.75,118.424c-1.689,0-3.406-0.332-5.061-1.031c-6.611-2.798-9.704-10.426-6.906-17.038
                    c17.586-41.559,65.703-61.062,107.261-43.476c6.611,2.798,9.704,10.426,6.906,17.038c-2.799,6.612-10.425,9.703-17.039,6.906
                    c-28.354-11.998-61.186,1.309-73.183,29.663C136.629,115.445,131.815,118.424,126.75,118.424z" stroke="#AAAAAA" fill="#FFFFFF"/>
              </svg>
              <INVISIBLE_PARAM_MENU_BUTTON ignore_mask_file="true" cursor="system::hand" param_id="gui.zoom" positions_count="14" width="100%" height="100%">
                  <PARAM_TOOLTIP param_id="gui.zoom" content="Zoom: {text_value}{unit}"/>
              </INVISIBLE_PARAM_MENU_BUTTON >
            </LAYER_STACK>
          </ROW>

          <!-- script name and invisible refresh buttons -->
          <TEXT string_id="$script_name_string$" id="script_title.text" font_weight="bold" font_size="14" v_offset="0">
            <ROW width="100%" height="100%" >

              <INVISIBLE_ACTION_BUTTON action="ReloadMainSkin" width="30%" height="100%" cursor="system::hand">
                <TOOLTIP text="Reload skin"/>
              </INVISIBLE_ACTION_BUTTON>

              <INVISIBLE_ACTION_BUTTON action="ReloadScript" width="70%" height="100%" cursor="system::hand">
                <TOOLTIP text="Reload script"/>
              </INVISIBLE_ACTION_BUTTON>

            </ROW>
          </TEXT>

          <!-- menu left side icons -->
          <ROW spacing="3" h_align="right" h_offset="-2">
            <IF condition="$SCRIPT_EDIT_MODE$">
              <!-- load/save scripts menu -->
              <LAYER_STACK h_offset="-1">
                <svg width="16" height="16" viewBox="30 25 50 50"><polyline points="55.63 30.4 55.63 41.28 66.58 41.28" stroke="#ffffff" stroke-width="3" /><path d="M54.29,30H37.37a3.28,3.28,0,0,0-3.28,3.28V66.72A3.28,3.28,0,0,0,37.37,70H63.63a3.28,3.28,0,0,0,3.28-3.28V42.62A3.23,3.23,0,0,0,66,40.34l-9.39-9.39A3.23,3.23,0,0,0,54.29,30Z" stroke="#ffffff" fill="none" stroke-width="3" /></svg>
                <STRING id="script_name_short" default="No Script"/>
                <ACTION id="ShowDefaultScriptsMenu" type="DisplayPlugNScriptMenu" script_file_name_string_id="script_name_short" name="Select script" />
                <INVISIBLE_ACTION_BUTTON action="ShowDefaultScriptsMenu" width="100%" height="100%" cursor="system::hand">
                  <TOOLTIP text="Select script"/>
                </INVISIBLE_ACTION_BUTTON>
              </LAYER_STACK>
            </IF>

            <LAYER_STACK v_offset="0" h_offset="-2">
              <svg width="16" height="16" viewBox="20 20 60 60"><polygon points="51.2,62.7 69,45 33,45" stroke="#777777" fill="white" /></svg>
              <INVISIBLE_ACTION_BUTTON action="menu_pns_curscript.Popup" width="100%" height="100%" cursor="system::hand">
                <TOOLTIP text="Current script menu"/>
              </INVISIBLE_ACTION_BUTTON>
              <POPUP_MENU id="menu_pns_curscript">

                <!-- actions for current script -->
                <ACTION id="OpenScriptFile" type="OpenUrl" url_string_id="$script_file_path$" application_string_id="edit_script_app" name="Edit CXX File" />
                <ACTION id="OpenKUIMLFile" type="OpenUrl" url_string_id="$script_gui_path$" application_string_id="edit_kuiml_app" name="Edit KUIML file" />
                <ACTION id="OpenScriptDirectory" type="OpenUrl" url_string_id="$script_file_path$" application="$FILE_EXPLORER_APP$" name="Open script folder"/>
                <MENU_ITEM action_id="ReloadScript" />
                <MENU_ITEM action_id="OpenScriptFile" />
                <MENU_ITEM action_id="OpenKUIMLFile" />
                <MENU_ITEM action_id="OpenScriptDirectory" />
                <MENU_SEPARATOR />
                
                <!-- actions for current skin -->
                <!-- get skin filename from top level file -->
                <STRING id="MainSkinFilename" default="$_SKIN_FILENAME_$" />
                <!-- for windows explorer we have to change / to \ -->
                <STRING id="MainSkinFilenamePrep" default="$_FILE_$" />
                <AT event_id="window.loaded.value_changed" condition_formula="window.loaded == 1" requires="MainSkinFilename;MainSkinFilenamePrep" script="if (&quot;$_SYSTEM_TYPE_$&quot; == &quot;Windows&quot;) { array&lt;string> ars; string s = MainSkinFilename; ars = s.split(&quot;/&quot;); string s2 = join(ars, &quot;\\&quot;); MainSkinFilenamePrep = s2; }  " />
                <ACTION id="OpenSkinFile" type="OpenUrl" url_string_id="MainSkinFilenamePrep" application_string_id="edit_kuiml_app" name="Edit skin file" />
                <ACTION id="OpenSkinDir" type="OpenUrl" url_string_id="MainSkinFilenamePrep" application="$FILE_EXPLORER_APP$" name="Open skin folder" />
                <MENU_ITEM action_id="ReloadMainSkin" />
                <MENU_ITEM action_id="OpenSkinFile" />
                <MENU_ITEM action_id="OpenSkinDir" />
                <MENU_SEPARATOR />

                <!-- actions for log -->
                <ACTION id="OpenLogFile" type="OpenUrl" url_string_id="$log_file_path$"  application_string_id="open_log_app" name="Open log file" />
                <MENU_ITEM action_id="OpenLogFile" />
                
                <!-- unused action to open script help file -->
                <ACTION id="OpenScriptDoc" type="OpenUrl" url_string_id="$script_doc_path$"/>
              </POPUP_MENU>
            </LAYER_STACK>

          </ROW>

        </LAYER_STACK>
      </ROW> <!-- // END TOP ROW -->

    </LAYER_STACK>