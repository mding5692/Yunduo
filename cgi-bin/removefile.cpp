#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <dirent.h>

using namespace std;

int main() {

        DIR *dir;
        struct dirent *ent;

        cout << "Content-type: text/html" << endl << endl;
        cout << "<html> \n";
        cout << "<head><title>Remove files</title></head>\n";
        cout << "<body>\n";

        cout << "<p><b>Below are the files currently in your directory</b></p>";
        cout << "<p> Remove files by pressing on them </p>";

        if ((dir = opendir("/var/www/html/saveFile")) != NULL) {
                while ((ent = readdir(dir)) != NULL) {

                        string dirName = string(ent->d_name);

                        if (dirName.compare(".") == 0 || dirName.compare("..") == 0) {
                                continue;
                        }

                        cout << "<br>";
                        string fileName  = "..//saveFile/" + dirName;

                        //-------------------------
                        if(remove(fileName)==0){
                          cout<<"remove successfully"<<endl;
                        }
                        else{
                          cout<<"remove fail"<<endl;
                        }


                        //-------------------------


			cout << "<button> remove file </button>";
                        cout << "<br>";

                }
                closedir(dir);
        } else {
                cout << "Unable to open directory" << endl;
        }

        cout << "</body></html>";

        return 0;
}
