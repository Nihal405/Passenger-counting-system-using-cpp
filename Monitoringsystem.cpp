#include <iostream>
#include <map>
#include <vector>
#include <ctime>

using namespace std;

const int MAX_PASSENGERS = 50;

struct Passenger {
    string name;
    string destination;
    int fare;
    time_t time;
    Passenger(string name, string destination, int fare, time_t time) : name(name), destination(destination), fare(fare), time(time) {}
};

int main() {
    int boarding_count = 0;
    int current_stop = 1;
    map<int, int> stop_boarding_count;
    vector<Passenger> passenger_database;
    int fare_per_kilometer = 10;

    cout << "Welcome to the Bus Passenger Monitoring System" << endl;
    cout << "Enter 1 to record a passenger boarding the bus at current stop" << endl;
    cout << "Enter 2 to simulate moving to the next stop" << endl;
    cout << "Enter 3 to view the passenger database" << endl;
    cout << "Enter 0 to exit the system" << endl;

    int action;
    while (true) {
        cout << "Enter action: ";
        cin >> action;

        if (action == 1) {
            
            if (boarding_count >= MAX_PASSENGERS) {
                cout << "Error: Bus is full. Cannot board more passengers." << endl;
            } else {
                string name;
                string destination;
                cout << "Enter passenger name: ";
                cin >> name;
                cout << "Enter passenger destination: ";
                cin >> destination;
                int fare;
                string mulki = "mulki";
                string surathkal = "surathkal";
                if(destination == mulki){
                    fare=25;
                }
                else if(destination == surathkal){
                    fare=15;
                }
                else{
                   fare==0;
                }
                time_t now = time(0);
                passenger_database.push_back(Passenger(name, destination, fare, now));
                boarding_count++;
                stop_boarding_count[current_stop]++;
                cout << "Passenger " << name << " recorded successfully with fare " << fare << endl;
            }
        } else if (action == 2) {
           
            current_stop++;
            cout << "Moved to stop " << current_stop << endl;
        } else if (action == 3) {
           
            cout << "Passenger database: " << endl;
            int total_fare = 0;
            cout << "Name\tDestination\tFare\tTime" << endl;
            for (const auto &passenger : passenger_database) {
                cout << passenger.name << "\t"
                     << passenger.destination << "\t\t"
                     << passenger.fare << "\t"
                     << ctime(&passenger.time) << endl;
                total_fare += passenger.fare;
            }
            cout << "Total fare collected: " << total_fare << endl;
        } else if (action == 0) {
            break;
        } else {
            cout << "Invalid action. Please try again." << endl;
        }
    }

    cout << "Exiting the Bus Passenger Monitoring System" << endl;
    cout << "Passenger boarding count at each stop: " << endl;
    for (auto const &stop : stop_boarding_count) {
        cout << "Stop " << stop.first << ": " << stop.second << " passengers" << endl;
    }

    return 0;
}
