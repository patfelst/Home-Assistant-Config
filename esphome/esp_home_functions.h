
/* 
** convert a number of seconds to a human readable C++ string of in the format:
** "dd hh mm ss" - Exclude fields that are zero, except for seconds
*/
std::string seconds_to_readable_0(int sec) {
  int seconds = sec;
  int minutes = 0;
  int hours = 0;
  int days = 0;
  std::string txt = "";

  days = seconds / (24 * 3600);
  seconds = seconds % (24 * 3600);
  hours = seconds / 3600;
  seconds = seconds % 3600;
  minutes = seconds /  60;
  seconds = seconds % 60;

  if (days)
    txt = to_string(days) + "d ";
  
  if (hours)
    txt += (to_string(hours) + "h ");
  
  if (minutes)
    txt += (to_string(minutes) + "m ");
  
  txt += to_string(seconds) + "s";

  return txt;
}

/* 
** convert a number of seconds to a human readable C++ string of in the format:
** "hh mm ss" - No days and include fields that are zero
*/
std::string seconds_to_readable_1(int sec) {
  int seconds = sec;
  int minutes = 0;
  int hours = 0;
  int days = 0;
  std::string txt = "";

  days = seconds / (24 * 3600);
  seconds = seconds % (24 * 3600);
  hours = seconds / 3600;
  seconds = seconds % 3600;
  minutes = seconds /  60;
  seconds = seconds % 60;

  txt = (to_string(hours) + "h ");
  txt += (to_string(minutes) + "m ");
  txt += to_string(seconds) + "s";
  return txt;
}

/* 
** convert a number of seconds to a human readable C++ string of in the format:
** "hh:mm:ss" - No days and include fields that are zero, separated by colons
*/
char *seconds_to_readable_2(int sec) {
  int seconds = sec;
  int minutes = 0;
  int hours = 0;
  int days = 0;
  static char txt[30] = "";

  days = seconds / (24 * 3600);
  seconds = seconds % (24 * 3600);
  hours = seconds / 3600;
  seconds = seconds % 3600;
  minutes = seconds /  60;
  seconds = seconds % 60;

  // ESP_LOGE("debug", "times = %02d, %02d, %02d, %02d", days, hours, minutes, seconds);        // y-coord is half of expected
  sprintf(txt, "%d:%02d:%02d", hours, minutes, seconds);
  // ESP_LOGE("debug", "txt = %s", txt);        // y-coord is half of expected
  return txt;
}