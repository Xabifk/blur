

std::vector<std::string> std::string split(std::string &original_string, std::string &separator)
{
    std::vector<std::string> tokens;

    size_t prev = 0, pos = 0;
    do
    {
        pos = original_string.find(separator, prev);
        if (pos == string::npos) 
        {
            pos = original_string.length();
        }

        string token = original_string.substr(prev, pos - prev);

        if (!token.empty()) 
        {
            tokens.push_back(token);
        }

        prev = pos + separator.length();
    } while (pos < original_string.length() && prev < original_string.length());

    return tokens;

}