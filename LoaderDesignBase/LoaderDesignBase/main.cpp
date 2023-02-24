#include <Lmcons.h>
#include "Windows.h"
#include <iostream>
#include "auth.hpp"
#include <string>
#include "skStr.h"
std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);

using namespace KeyAuth;
using namespace std;

std::string name = (std::string)skCrypt(""); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = (std::string)skCrypt(""); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = (std::string)skCrypt(""); // app secret, the blurred text on licenses tab and other tabs
std::string version = (std::string)skCrypt("1.0"); // leave alone unless you've changed version on website
std::string url = (std::string)skCrypt("https://keyauth.win/api/1.2/"); // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);

int main()
{

    HWND consoleWindow = GetConsoleWindow();

    // Set the console window transparency
    SetWindowLong(consoleWindow, GWL_EXSTYLE,
        GetWindowLong(consoleWindow, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(consoleWindow, 0, 200, LWA_ALPHA);



    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    

        SetConsoleTextAttribute(hConsole, 15);

        // "[" und "]" in rot drucken
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "\n\n\n[";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << ">";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "]";
        SetConsoleTextAttribute(hConsole, 15);
        {
            TCHAR name[UNLEN + 1];
            DWORD size = UNLEN + 1;

            if (GetUserName((TCHAR*)name, &size))
                wcout << L" Hello, " << name << L"!\n";
            else
                cout << " Hello, unnamed person!\n";
        }
        std::cout << std::endl;
        Sleep(3000);




        SetConsoleTextAttribute(hConsole, 15);

        // "[" und "]" in rot drucken
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "\n\n\n[";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << ">";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "]";
        SetConsoleTextAttribute(hConsole, 15);
        std::string consoleTitle = (std::string)skCrypt(" Loader - Built at:  ") + compilation_date + " " + compilation_time;
        SetConsoleTitleA(consoleTitle.c_str());
        KeyAuthApp.init();
        if (!KeyAuthApp.data.success)
        {
            std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
            Sleep(1500);
            exit(0);
        }
        system("cls");

        if (KeyAuthApp.checkblack()) {
            abort();
        }

        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "\n\n\n[";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << "1";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "]";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << " Login";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "\n[";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << "2";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "]";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << " Register \n";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "\n[";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << ">";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "] ";
        SetConsoleTextAttribute(hConsole, 15);



        int option;
        std::string username;
        std::string password;
        std::string key;

        std::cin >> option;
        switch (option)
        {

        case 1:
            system("cls");
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "\n\n\n[";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << ">";
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "]";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << " Enter username:  ";
            std::cin >> username;
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "\n\n[";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << ">";
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "]";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << " Enter password:  ";
            std::cin >> password;
            KeyAuthApp.login(username, password);
            break;
        case 2:
            system("cls");
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "\n\n\n[";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << ">";
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "]";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << " Enter username:  ";
            std::cin >> username;
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "\n\n[";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << ">";
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "]";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << " Enter password:  ";
            std::cin >> password;
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "\n\n[";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << ">";
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "]";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << " Enter license:  ";
            std::cin >> key;
            KeyAuthApp.regstr(username, password, key);
            break;
        default:
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "\n\n[";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << ">";
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "]";
            SetConsoleTextAttribute(hConsole, 15);
            std::cout << " Invalid Selection!\n";
            Sleep(3000);
            exit(0);
        }
        if (!KeyAuthApp.data.success)
        {
            std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
            Sleep(1500);
            exit(0);
        }
        Sleep(2000);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "\n\n\n[";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << ">";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "]";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << skCrypt(" Hello ") << KeyAuthApp.data.username;
        std::cout << ", and welcome to CheatName!";
        Sleep(3000);
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);

        std::cout << "\n\n\n[";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << "1";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "]";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << " Load Cheat";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "\n[";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << "2";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "]";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << " Spoof";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "\n\n[";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << ">";
        SetConsoleTextAttribute(hConsole, 12);
        std::cout << "]";
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << " Your selection: ";

        int option1;
        std::cin >> option1;
        switch (option1)
        {
        case 1:
            break;
            //Your Cheat Loading Code
        case 2:
            break;
            //Your Spoofer Code
        }






        return 0;
    }



