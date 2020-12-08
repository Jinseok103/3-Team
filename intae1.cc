#include <fstream>		//log file
#include <string>		//log file

class GameTable {
		private:
				int high_score;
				fstream log_file;
				
				void LoadHighScore() {

						string line;
						string init_line = "0\n0\n0\n";

						log_file.open("gamelog_highscore.txt", ios::in);

						if (log_file.is_open()) {

								log_file.seekg(0, ios::beg);
								for (int i = 0; i < 3; i++) {
										getline(log_file, line);
										cur_highscore[i] = stoi(line);
								}
						}
						else {
								log_file.open("gamelog_highscore.txt", ios::app);

								for (int i = 0; i < 3; i++) {
										cur_highscore[i] = 0;
								}
								log_file.write(init_line.c_str(), init_line.size());
						}
						log_file.close();
				}

				void ChangeHighScore(int song_index, int new_score) {
						string line;
						log_file.open("gamelog_highscore.txt", ios::out);
						log_file.seekg(0, ios::beg);
						string new_high_score;

						for (int i = 0; i < 3; i++) {
								if (i != song_index) {
										line = to_string(cur_highscore[i]);
								}
								else {
										if (new_score > cur_highscore[i]) {
												line = to_string(new_score);
										}
										else {
												line = to_string(cur_highscore[i]);
										}
								}
								new_high_score.append(line);
								new_high_score.append("\n");
						}
						log_file.write(new_high_score.c_str(), new_high_score.size());
						log_file.close();
				}

};
