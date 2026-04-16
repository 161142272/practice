#include <iostream>
using namespace std;

int main()
{
    int t, n;
    for (int i = 0; i < t; i++)
    {
        char sp;
        cin >> sp;
        cin >> n;

        if (sp == 'I')
        {
            int* number = new int[n];
            for (int j = 0; j < n; j++)
            {
                cin >> *(number + j);
            }

            int sum;
            for (int j = 0; j < n; j++)
            {
                sum += *(number + j);
            }
            cout << sum / n << endl;
        }

        if (sp == 'C')
        {
            char* number = new char[n];
            for (int j = 0; j < n; j++)
            {
                cin >> *(number + j);
            }

            char max;
            max = *number;
            for (int j = 0; j < n; j++)
            {
                if (max < *(number + j))
                {
                    max = *(number + j);
                }
            }
            cout << max << endl;

        }

        if (sp == 'F')
        {
            float* number = new float[n];
            for (int j = 0; j < n; j++)
            {
                cin >> *(number + j);
            }

            int min;
            min = *number;
            for (int j = 0; j < n; j++)
            {
                if (min > *(number + j))
                {
                    min = *(number + j);
                }
            }
            cout << min << endl;
        }
    }

}