#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>
#include <string.h>
using namespace std;


int main(void)
{   
    /* initialize variables*/
    char str[11], *s = str;
    struct stat st;
    mode_t owner, group, other;
    string username = "admin";
    double file_size = 14*(2<<12);
    vector<string> v;
    string path;

    /* list files in a path*/
    cout << "Enter path to check files" << endl;
    cin >> path;
    DIR* dirp = opendir(path.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
            v.push_back(dp->d_name);
    }
    closedir(dirp);
    
    /* Check file*/
    for (auto i : v){

        if(stat(i.c_str(), &st) < 0)
        {
            printf("Couldn't open file.\n");
       
        }   

        struct passwd *pw = getpwuid(st.st_uid);
        struct group  *gr = getgrgid(st.st_gid);
  
        
        if ((username.compare(pw->pw_name)!=-1) && (st.st_mode & S_IXUSR) && ((double)st.st_size > file_size)){
           cout << "The file is:"   << i << endl;
        }
    }
  return 0;
}   