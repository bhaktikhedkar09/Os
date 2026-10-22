#include <iostream>
using namespace std;

int main()
{
int b[5] = {100, 500, 200, 300, 600};
int p[4] = {212, 417, 112, 426};
int i, j, pos;

for (int type = 1; type <= 3; type++)
{
int a[5];
int count = 0, used = 0;

for (i = 0; i < 5; i++)
a[i] = b[i];

cout << "\n";

if (type == 1) cout << "FIRST FIT\n";
if (type == 2) cout << "BEST FIT\n";
if (type == 3) cout << "WORST FIT\n";

cout << "Process\tSize\tBlock\n";

for (i = 0; i < 4; i++)
{
pos = -1;

for (j = 0; j < 5; j++)
{
if (a[j] >= p[i])
{
if (type == 1)
{
pos = j;
break;
}

if (pos == -1 ||
(type == 2 && a[j] < a[pos]) ||
(type == 3 && a[j] > a[pos]))
pos = j;
}
}

if (pos != -1)
{
cout << i + 1 << "\t" << p[i]
<< "\t" << pos + 1 << endl;

a[pos] -= p[i];
count++;
used += p[i];
}
else
cout << i + 1 << "\t" << p[i]
<< "\tNot allocated\n";
}

int free = 0;

for (i = 0; i < 5; i++)
free += a[i];

cout << "Allocated: " << count << endl;
cout << "Free memory: " << free << endl;
cout << "Utilization: "
<< used * 100.0 / 1700 << "%\n";
}

return 0;
}