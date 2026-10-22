#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Function to read IP address
void readIP(string ip, int a[])
{
stringstream ss(ip);
char dot;

ss >> a[0] >> dot >> a[1] >> dot
>> a[2] >> dot >> a[3];
}

int main()
{
string ip1, ip2, mask;
int a[4], b[4], m[4];

cout << "Enter first IP address: ";
cin >> ip1;

cout << "Enter second IP address: ";
cin >> ip2;

cout << "Enter subnet mask: ";
cin >> mask;

readIP(ip1, a);
readIP(ip2, b);
readIP(mask, m);

// Validate IP addresses
for(int i = 0; i < 4; i++)
{
if(a[i] < 0 || a[i] > 255 ||
b[i] < 0 || b[i] > 255 ||
m[i] < 0 || m[i] > 255)
{
cout << "Invalid IP or subnet mask!";
return 0;
}
}

cout << "\nBoth IP addresses are valid.";

// Check subnet
bool same = true;

for(int i = 0; i < 4; i++)
{
if((a[i] & m[i]) != (b[i] & m[i]))
same = false;
}

if(same)
cout << "\nBoth IPs belong to the same subnet.";
else
cout << "\nBoth IPs belong to different subnets.";

return 0;
}