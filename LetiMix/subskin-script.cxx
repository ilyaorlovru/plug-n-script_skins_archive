void replaceString(string & ioString,const string &in stringToFind,const string &in replaceString)
{
    array<string>@ pieces=ioString.split(stringToFind);
    if(@pieces!=null)
    {
      if(pieces.length>0)
        ioString=pieces[0];
      for(uint i=1;i<pieces.length;i++)
      {
          ioString+=replaceString;
          ioString+=pieces[i];
      }
    }
}

void reloadSubSkin() {
  file f;
  if (f.open($script_gui_path$, "r") >= 0) {
        controls_widget.innerKUIML=f.readString(f.getSize());
        f.close();
    } else {
        if (f.open("$_DIR_$/subskin-template.kuiml", "r") >= 0) {
              string content = f.readString(f.getSize());

              string value = int($script_input_params_count$);
              replaceString(content, "#in_params_count#", value);
              value = int($script_output_params_count$);
              replaceString(content, "#out_params_count#", value);

              controls_widget.innerKUIML = content;
              f.close();
          }
    }
    log_area.display=0;
  }