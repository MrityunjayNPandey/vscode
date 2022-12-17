{
  int m;
  cin >> m;
  vector<string> wall(2);
  cin >> wall[0];
  cin >> wall[1];
  if (m == 1) {
    cout << "YES\n";
    continue;
  }
  pair<int, int> lastvisited;
  lastvisited = {-1, -1};
  int f = 0, lvwb = -1, lvbw = -1;
  for (int i = 0; i < m; i++) {
    if (wall[0][i] == 'B' && wall[1][i] == 'W') {

      if (lvwb > lvbw) {
        if ((i - lvwb) % 2 == 1) {
          f = 1;
          break;
        }
      } else if (lvwb < lvbw) {
        if ((i - lvbw) % 2 == 0) {
          f = 1;
          break;
        }
      }
      lvbw = i;
    } else if (wall[1][i] == 'B' && wall[0][i] == 'W') {

      if (lvwb > lvbw) {
        if ((i - lvwb) % 2 == 0) {
          f = 1;
          break;
        }
        lvwb = i;
      } else if (lvwb < lvbw) {
        if ((i - lvbw) % 2 == 1) {
          f = 1;
          break;
        }
        lvwb = i;
      }
      lvwb = i;
    }
  }

  if (f)
    cout << "NO\n";
  else
    cout << "YES\n";
}
return 0;
}