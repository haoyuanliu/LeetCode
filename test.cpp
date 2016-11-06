public class Solution
{
    public bool IsMatch(string s, string p)
    {
        if (p.Length == 0)
            return s.Length == 0;

        if (p.Length == 1)
            return (s.Length == 1) && (p[0] == s[0] || p[0] == '.');

        if (p[1] != '*')
        {
            if (s.Length == 0)
                return false;
            else
                return (s[0] == p[0] || p[0] == '.')
                       && IsMatch(s.Substring(1), p.Substring(1));
        }
        else
        {
            while (s.Length > 0 && (p[0] == s[0] || p[0] == '.'))
            {
                if (IsMatch(s, p.Substring(2)))
                    return true;
                s = s.Substring(1);
            }
            return IsMatch(s, p.Substring(2));
        }
    }
}
