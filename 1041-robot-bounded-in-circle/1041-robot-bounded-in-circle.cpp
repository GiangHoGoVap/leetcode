class Solution
{
public:
    void follow(int &x, int &y, int &dx, int &dy, char instruction)
    {
        if (instruction == 'L')
        {
            if (dx == 1 && dy == 0)
            {
                dx = 0;
                dy = 1;
            }
            else if (dx == -1 && dy == 0)
            {
                dx = 0;
                dy = -1;
            }
            else if (dx == 0 && dy == 1)
            {
                dx = -1;
                dy = 0;
            }
            else if (dx == 0 && dy == -1)
            {
                dx = 1;
                dy = 0;
            }
        }
        else if (instruction == 'R')
        {
            if (dx == 1 && dy == 0)
            {
                dx = 0;
                dy = -1;
            }
            else if (dx == -1 && dy == 0)
            {
                dx = 0;
                dy = 1;
            }
            else if (dx == 0 && dy == 1)
            {
                dx = 1;
                dy = 0;
            }
            else if (dx == 0 && dy == -1)
            {
                dx = -1;
                dy = 0;
            }
        }
        else
        {
            x += dx;
            y += dy;
        }
    }

    bool isRobotBounded(string instructions)
    {
        int dx = 1;
        int dy = 0;
        int x = 0;
        int y = 0;
        int n = 4;

        while (n--)
        {
            for (int i = 0; i < instructions.length(); i++)
            {
                follow(x, y, dx, dy, instructions[i]);
            }
        }
        if (x == 0 && y == 0)
            return true;
        return false;
    }
};