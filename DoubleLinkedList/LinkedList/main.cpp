#include <iostream>
#include "linked_list.h"
using namespace std;

int main()
{
	linked_list list, list2, list3;
	int choice,n,m,position,i, startPos, endPos;
	while(1)
	{
		cout<<"1. Create List"<<endl;
		cout<<"2. Add at beginning"<<endl;
		cout<<"3. Add after"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Count"<<endl;
		cout<<"7. Reverse"<<endl;
		cout<<"8. Search"<<endl;
        cout<<"9. Concatinate"<<endl;//1
        cout<<"10. Clone" << endl;
        cout<<"11. Move First Node to End"<<endl//1;
		cout<<"12. Move Last Node to Start"<<endl;//1
		cout<<"13. Split List at Center" << endl;//1
		cout<<"14. Sublist"<<endl;//1
		cout<<"15. Quit" << endl;

		cout<<"Enter ur choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"How many nodes u want:"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"Enter the element"<<endl;
					cin>>m;
					list.create_list(m);
				}
				break;
			case 2:
				cout<<"Enter the element"<<endl;
				cin>>m;
				list.add_at_beginning(m);
				break;
			case 3:
				cout<<"Enter the element"<<endl;
				cin>>m;
				cout<<"Enter the position after which this element is inserted"<<endl;
				cin>>position;
				list.add_after(m,position);
				break;
			case 4:
				if(list.start == NULL)
				{
					cout<<"List is empty"<<endl;
					continue;
				}
				cout<<"Enter the element for deletion"<<endl;
				cin>>m;
				list.del(m);
				break;
			case 5:
				list.display();
				break;
			case 6:
				list.count();
				break;
			case 7:
				list.rev();
				break;
			case 8:
				cout<<"Enter the element to be searched"<<endl;
				cin>>m;
				list.search(m);
				break;
            case 9:
                cout<<"Create a new list to Concatenate in Old List" << endl;
                cout<<"How many nodes u want:"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"Enter the element"<<endl;
					cin>>m;
					list2.create_list(m);
				}

                cout<<"Concatinated List: "<<endl;
                list.concatinate(list2);
				list.display();
				break;
			case 10:
				cout << "Before Copying Data From List: ";
				list.display();
				cout << endl << "After Copying Data From List: ";
				list2.clone(list);
				list2.display();
				break;
			case 11:
				list.move_start_to_last();
				break;
			case 12:
				list.move_last_to_start();
				break;
			case 13:
				list.split_at_center();
			case 14:
				cout << "Enter Start Position: ";
				cin >> startPos;
				cout << endl << "Enter End Position: ";
				cin >> endPos;
				list.sublist(startPos, endPos);
			case 15:
				exit(1);
			default:
				cout<<"Wrong Choice"<<endl;
				break;
		}
	}

    return 0;
}
