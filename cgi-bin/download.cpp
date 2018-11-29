/* @Authors: CS 3307 Group 17
 * @brief: Displays files that can be downloaded from saveFile directory
 * @detailed: We implement in our main function, code that can access our saveFile directory, 
 * search for the files in there and then display them as downloadable on our html UI, 
 * if we can't find or open the saveFile directory, an error message saying Unable to open directory
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <dirent.h>

using namespace std;

int main() {
	// Declares system variables for opening up saveFile directory	
	DIR *dir;
	struct dirent *ent;

	// cout or our output is directed to html, so this code will be displayed 
	// on our html pages
	// the following html and css lines structure and style the ui for 
	// the download page
	cout << "Content-type: text/html" << endl << endl;
	cout << "<html><head><meta charset='UTF-8'><meta name='description' content='CS3307-website'><meta name='author' content='CS3307-group17'><title>Personal Service</title><link href='https://fonts.googleapis.com/css?family=Open+Sans:400,300,700' rel='stylesheet' type='text/css'><link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css'><style type='text/css' media='screen'> * { box-sizing: border-box; margin: 0; padding: 0;} body { background: #434343; color: #FFFFFF; font-family: 'Open Sans', sans-serif; font-weight: 300; font-size: 0.9em;} ul { list-style: none;} /** * top header */ .top-header { align-items: center; background: #4b89df; box-shadow: 0px 2px 10px #333333; display: flex; height: 60px; position: fixed; top: 0; width: 100%; z-index: 1;} .avatar { background: #FFFFFF; border-radius: 50%; color: #333C4D; height: 40px; margin-left: 20px; padding-left: 9px; padding-top: 5px; width: 40px; } /** * top navigation */ .top-nav a { color: #F9F9F9; font-weight: 400; margin-left: 20px; text-decoration: none; } /** * main container */ .container { margin: 60px auto; max-width: 1000px; min-width: 600px; } /** * main header */ .container > header { align-items: center; background-size: 100%; display: flex; height: 250px; } .container > header p { border-left: 1px solid #FFFFFF; font-weight: 400; font-size: 2em; line-height: 1em; margin-left: 220px; padding-left: 5px; } .container > header span { color: #1e90ff; } /** * main section */ .main-section { background: #778899; } /** * aside */ .main-section aside { float: left; width: 180px; } .nav-icon { color: #624630; padding: 20px; text-align: center; } /** * main navigation */ .main-nav-btn { background: none; border-top: 1px solid #FFFFFF; color: #FFFFFF; display: block; padding: 20px; text-align: left; text-decoration: none; } .main-nav-btn:hover { background: rgba(255, 255, 255, 0.8); color: #624630; } .main-nav-btn.active { background: #d3d3d3; color: #624630; } .main-nav-btn i { width: 20px; } /** * file list */ .file-list { background: #d3d3d3; list-style: none; margin-left: 180px; min-height: 500px; padding: 10px; } /** * file */ .file { align-items: center; border-bottom: 1px solid #FFFFFF; color: #624630; display: flex; margin: 10px; padding: 15px; transition: background-color 100ms linear; } .file:last-child { border: none; } .file:hover { background: rgba(255, 255, 255, 0.8); transition: background-color 100ms linear; } .file img { border: 1px solid #FFFFFF; height: 80px; width: 80px; } .file div:first-of-type { flex: 1; margin-left: 10px; margin-right: 10px; } .file-name { color: #624630; font-weight: 400; text-decoration: none; } .file-name:hover { text-decoration: underline; } .file-address { line-height: 20px; padding-right: 20px; text-align: right; } .stars { align-items: center; display: flex; padding-top: 10px; } .fav-link { border-left: 1px solid #FFFFFF; cursor: pointer; line-height: 60px; text-align: center; width: 60px; } .fav-link:hover { color: #F13F3F; } /** * footer section */ footer { background: #434343; font-size: 0.8em; height: 200px; position: relative; } footer p { text-align: center; } footer p.title { font-size: 1.2em; padding: 15px; } footer ul { align-items: center; display: flex; padding: 20px; } footer ul li { flex: 1; } </style> </head> <body> <header class='top-header'> <i class='avatar fa fa-user fa-2x'></i> <nav class='top-nav'> <a href='cgi-bin/login.cgi'>Home</a> <a href='upLoad.html'>Files</a> <a href='cgi-bin/login.cgi'>About</a> <a href='#'>Logout</a> </nav> </header> <section class='container'> <header> <p> <span>Personal Services</span> <br /> UWO.云朵 </p> </header>" << endl;

	// Description of what to do is printed on html
	cout << "<p><b>Below are the files currently in your directory</b></p>";
	cout << "<p> Download files by pressing on them, click the button beside it to delete them </p>";
        cout<< "<META HTTP-EQUIV='refresh' CONTENT='10'>";

	// Directory where files is saved is in /var/www/html/saveFile directory
	if ((dir = opendir("/var/www/html/saveFile")) != NULL) {	
		///target the file where all upload files are being stored and check if it is empty
		while ((ent = readdir(dir)) != NULL) {

			string dirName = string(ent->d_name);
			// Makes sure it isnt the keywords for . (current directory) or .. (parent directory)
			if (dirName.compare(".") == 0 || dirName.compare("..") == 0) {
				continue;
			}

			cout << "<br>";
			string fileName  = "..//saveFile/" + dirName;  ///saving the real dirName 
			string fullfileName = "/var/www/html/saveFile/" + dirName;	///saving the full name of the dirName 
			// Download link is created, once user presses on this link, the file is downloaded to user's computer
			cout << "<a href=' " << fileName.c_str() << "'" <<  " download='download'>" << ent->d_name << "</a>" << endl;	
			cout << "<form action='removefile.cgi' target='_blank'> <input type = 'hidden' name = 'path' value = '" <<fullfileName.c_str() << "'> <input type='submit' value='delete'></form>";	
			// Remove file button enables user to delete file once this button is pressed
			cout << "<br>";
		
		}
		closedir(dir);
	} else { // Error msg if unable to open the directory	
		cout << "Unable to open directory" << endl;
	}

	// Footer and rest of the html is printed to the download page
	cout << " <footer> <p class='title'>What We Do</p> <p>Help you control the best cloud around.</p> <ul> <li> <p><i class='fa fa-globe fa-2x'></i></p> <p>London office, ON</p> </li> <li> <p><i class='fa fa-envelope-o fa-2x'></i></p> <p>info@uwo.com</p> </li> <li> <p><i class='fa fa-phone-square fa-2x'></i></p> <p>+1 123 234 567</p> </li> </ul> </footer> </body> </html>" << endl;


	return 0;
}

