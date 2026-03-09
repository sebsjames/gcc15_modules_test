module;

#include <algorithm>
#include <string>
#include <filesystem>

export module mplot.tools;

export namespace mplot
{
    // Used with std::transform, below
    struct to_lower { char operator() (const char c) const { return tolower(c); } };

    namespace tools
    {
        bool fileExists (const std::string& path)
        {
            if (std::filesystem::exists(path)) {
                if (std::filesystem::is_regular_file (path)
                    || std::filesystem::is_block_file (path)
                    || std::filesystem::is_socket (path)
                    || std::filesystem::is_fifo (path)
                    || std::filesystem::is_symlink (path)
                    || std::filesystem::is_character_file (path)) {
                    return true;
                }
            }
            return false;
        }

        void toLowerCase (std::string& str)
        {
            std::transform (str.begin(), str.end(), str.begin(), mplot::to_lower());
        }

    } // namespace tools
} // namespace mplot
