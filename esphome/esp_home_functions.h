
/* 
** convert a number of seconds to a human readable C++ string of in the format:
** "dd hh mm ss"
*/
std::string seconds_to_readable(int sec) {
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

  if (days) txt = (to_string(days) + "d "); else "";
  if (hours) txt+= (to_string(hours) + "h "); else "";
  if (minutes) txt+= (to_string(minutes) + "m "); else "";
  txt+= to_string(seconds) + "s";
  return txt;
}