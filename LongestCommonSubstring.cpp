#include <iostream>
using namespace std;

int main()
{
    string one = "";
    string two = "";

    // Read in the strings to compare
    cout << "Please enter string one (A-Z): " << endl;
    cin >> one;
    cout << "Please enter string two (A-Z): " << endl;
    cin >> two;

    // Inititalize everything
    int oneLength = one.length();
    int twoLength = two.length();
    int longestSubstringLength = 0;
    int indexOfSubstring;

    int grid[oneLength + 1][twoLength + 1];

    // Set the grid to 0s
    memset(grid, 0, sizeof(grid));

    // Create the grid
    for (int x = 1; x <= oneLength; x++)
    {
        for (int y = 1; y <= twoLength; y++)
        {
            if (one[x - 1] == two[y - 1])
            {
                grid[x][y] = grid[x - 1][y - 1] + 1;
            }
            if (grid[x][y] > longestSubstringLength)
            {
                // Store the length and index of the current longest substring
                longestSubstringLength = grid[x][y];
                indexOfSubstring = x;
            }
        }
    }

    cout << "2D Grid:" << endl;

    // Print out the grid
    for (int i = 0; i <= oneLength; i++)
    {
        for (int j = 0; j <= twoLength; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    // Print out the length of and the longest substring
    cout << "The longest substring length is: " << longestSubstringLength << endl;

    string longestCommonSubstring = one.substr(indexOfSubstring - longestSubstringLength, longestSubstringLength);

    cout << "The longest common substring is: " << longestCommonSubstring << endl;
}