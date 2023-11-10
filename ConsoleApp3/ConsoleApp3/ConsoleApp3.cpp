#include <iostream>
#include <vector>
#include "Date.h"
#include "Note.h"
#include "Notepad.h"

using namespace std;


int main()
{
    cout << " ----------------------------------" << endl;
    cout << " Hello)    Welcome to the Notepad! " << endl;
    cout << " ----------------------------------" << endl << endl;
    
    Notepad notes;

    Date birthDate_1(5, 10, 2000); 
    Note note_1("note1", "Nazar", "Pyvozavr", "876873678", birthDate_1);

    Date birthDate_2(15, 10, 1977);
    Note note_2("note2", "Tom", "Hardy", "3330909111", birthDate_2);

    Date birthDate_3(14, 03, 1988);
    Note note_3("note3", "Stephan", "Curry", "3330909111", birthDate_3);

    notes = notes + note_1 + note_2 + note_3;

    notes.SortByBirthDate();
    
    cout << " Select an option: " << endl;
    cout << " 1. Add note " << endl;
    cout << " 2. View existing notes " << endl;
    cout << " 3. Search note by " << endl;
    cout << " 4. Remove note " << endl;
    cout << "\n Option: ";

    int x{};
    while (x < 1 || x > 4) {
        cin >> x;

        if (x < 1 || x > 4) {
            cout << " Invalid option. Please select 1, 2, 3 or 4." << endl;
        }
    }
    cout << " ------------------------" << endl << endl;

    switch (x) {
    case 1:
        notes.AddNote();
        break;
    case 2:
        notes.ShowInfo();
        break;
    case 3:
        notes.SearchNote();
        break;
    case 4:
        notes.RemoveNote(); 
        break;
    }

    system("pause");  return 0;
}

