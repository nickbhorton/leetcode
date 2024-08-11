#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
/*
 * There is a grid of characters that can either be <space> '/' or '\'
 * the goal is to find the number of regions that are split by the slashes
 *
 * Example 1:
 * ----
 * | /| " /"
 * |/ | "/ "
 * ----
 * An equivilent is
 * "01"
 * "10"
 * The importance here is the diagonal nature of the 1's
 *
 * starting with the ' ' at zero zero we know we are inside of a region so there
 * is at least one region. As we look to the right we see a boundary that helps
 * contain our region. as we look up and left we see more boundarys that contain
 * our region. And again as we look down we see a boundary container. Therefore
 * we have found a region.
 *
 * It seems that the importance of a line is that it devides the space. so maybe
 * it would be better to look at the empty space as containing no useful
 * information. Then as we move to the (0, 1) "/" this potentially is a line
 * cutting the space. we look along the line to see it it hits the walls.
 * it does so we know we have a complete line. If instead we hit another
 * diagonal chip this does not make a complete line and therefor (MIGHT) not
 * matter.
 *
 * So we see we have a complete line This line could be qualified by a number
 * corrisponding to either the row or col it starts on lets pick rows for the
 * bottom left to top right lines. and cols for top left to bottom right lines.
 * This is how we will deal with duplicate lines. so we find that there is a
 * valid line we can call a row 1 line. When we look at (1,0) we can either walk
 * along the line and validate it again or check if it is a part of the stored
 * valid lines. Which ever is cheaper.
 * Then we look at (1,1) and see that we dont care. Now we see that there is one
 * row cut and zero col cuts. Therefore there is 2 regions. or n cuts plus one.
 *
 * Example 2:
 * "/\"
 * "\/"
 *
 * This example has two valid col lines and two valid row lines. So both would
 * independantly cut the space into three. There are 4 contact points and 5
 * regions maybe contact points are useful. or vertexes.
 *
 * Example 3:
 * This example shows that there needs to be more than one number to understand
 * a cut. Maybe it makes more send to define a root of a line that exists along
 * the left or bottom lb or right or bottom or rb So if we give importance to
 * the bottom arbitrarily we can call them left and right lines.
 * "///"
 * "///"
 * "///"
 *
 * We have validate left and right lines and have them being counted.
 * The test case that fails is
 * "\/"
 * "/\" which has 2 lines on left and one right. And then 4 sections
 *
 * "\/\/"
 * "/\/\"
 * "\/\/"
 * "/\/\"
 * This would also obviously fail as it has 3 r and 3 l lines and 12 regions
 *
 */

class Solution
{
public:
    bool validate_left_line(vector<string> const& grid, int row, int col)
    {
        if (grid[row][col] != '/') {
            return false;
        }
        int row_save = row;
        int col_save = col;
        // check up
        while (true) {
            row_save -= 1;
            col_save += 1;
            if (row_save < 0 || col_save > grid[0].size() - 1) {
                break;
            } else {
                if (grid[row_save][col_save] != '/') {
                    return false;
                }
            }
        }
        row_save = row;
        col_save = col;
        // check down
        while (true) {
            row_save += 1;
            col_save -= 1;
            if (col_save < 0 || row_save > grid.size() - 1) {
                break;
            } else {
                if (grid[row_save][col_save] != '/') {
                    return false;
                }
            }
        }
        return true;
    }
    bool validate_right_line(vector<string> const& grid, int row, int col)
    {
        if (grid[row][col] != '\\') {
            return false;
        }
        int row_save = row;
        int col_save = col;
        // check up
        while (true) {
            row_save -= 1;
            col_save -= 1;
            if (row_save < 0 || col_save < 0) {
                break;
            } else {
                if (grid[row_save][col_save] != '\\') {
                    return false;
                }
            }
        }
        row_save = row;
        col_save = col;
        // check down
        while (true) {
            row_save += 1;
            col_save += 1;
            if (col_save > grid[0].size() - 1 || row_save > grid.size() - 1) {
                break;
            } else {
                if (grid[row_save][col_save] != '\\') {
                    return false;
                }
            }
        }
        return true;
    }

    int regionsBySlashes(vector<string>& grid)
    {
        int const n = grid.size();
        int number_left_lines{};
        for (int i = 0; i < n; i++) {
            if (validate_left_line(grid, i, 0)) {
                number_left_lines++;
            }
        }
        for (int i = 1; i < n; i++) {
            if (validate_left_line(grid, n - 1, i)) {
                number_left_lines++;
            }
        }
        // std::cout << number_left_lines << "\n";
        int number_right_lines{};
        for (int i = 0; i < n; i++) {
            if (validate_right_line(grid, i, n - 1)) {
                number_right_lines++;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (validate_right_line(grid, n - 1, i)) {
                number_right_lines++;
            }
        }
        // std::cout << number_right_lines << "\n";
        return number_left_lines + number_right_lines + 1;
    }
};

int main()
{
    Solution s{};
    std::vector<std::string> grid = {"///", "/ /", "///"};
    std::cout << (s.validate_left_line(grid, 0, 0) == true);
    std::cout << (s.validate_left_line(grid, 1, 0) == true);
    std::cout << (s.validate_left_line(grid, 2, 0) == false);
    std::cout << (s.validate_left_line(grid, 0, 1) == true);
    std::cout << (s.validate_left_line(grid, 1, 1) == false);
    std::cout << (s.validate_left_line(grid, 2, 1) == true);
    std::cout << (s.validate_left_line(grid, 0, 2) == false);
    std::cout << (s.validate_left_line(grid, 1, 2) == true);
    std::cout << (s.validate_left_line(grid, 2, 2) == true);
    std::cout << "\n";

    std::vector<std::string> grid2 = {"\\\\\\", "\\ \\", "\\\\\\"};
    std::cout << (s.validate_right_line(grid2, 0, 0) == false);
    std::cout << (s.validate_right_line(grid2, 1, 0) == true);
    std::cout << (s.validate_right_line(grid2, 2, 0) == true);
    std::cout << (s.validate_right_line(grid2, 0, 1) == true);
    std::cout << (s.validate_right_line(grid2, 1, 1) == false);
    std::cout << (s.validate_right_line(grid2, 2, 1) == true);
    std::cout << (s.validate_right_line(grid2, 0, 2) == true);
    std::cout << (s.validate_right_line(grid2, 1, 2) == true);
    std::cout << (s.validate_right_line(grid2, 2, 2) == false);
    std::cout << "\n";

    s.regionsBySlashes(grid);
    s.regionsBySlashes(grid2);
}
