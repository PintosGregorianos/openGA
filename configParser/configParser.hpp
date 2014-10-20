/*--------------------------------------------------------------------------------------------
openGA: confiParser

    WHAT IS THIS:
        This file defines the configParser system. It is a multipurpose parser that can
            be used with any ASCII file. Tha parser can read and write parameters from/to
            a file or a std::string.

    FILE:
        The file need to be in the following format:
            -----------------------------------------
                parameter_name1 = value

                # comentary
                parameter_name2 = value
            ...
            -----------------------------------------
        Where "paramenter_name" is the name of the paramenter and "value" is the actual stored value.

        For use a line as comment start it with a #:
        -----------------------------------------
                parameter_name1 = value

                # My comment
                parameter_name2 = value
            ...
            -----------------------------------------

        You can OPTIONALY end line with a ; por organizion purpose like:
            -----------------------------------------
                name = gregory;
            ...
            -----------------------------------------

        The parse will ignore tabs and spaces, so you can organize the file as you like:
            ---------------------------------------------
                # Person parameters:
                    name =gregory;
                    age=13
                    male= yes

                    # birthday
                        day = 18;
                        month      = 01
                        year  = 1995 # younger than pinto
            ----------------------------------------------


    USING
        void parseFromString(const std::string &data);
        bool parseFromFile  (const std::string &file_name);

        You can parse the file. The fill will be read only at call and the data will be cached and mapped to memory as key => value

        **! All modifications will be cached and not writeen to file in real time.


    USING
        void writeToString  (std::string &data);
        bool writeToFile    (const std::string &file_name);

        You can write the cached data to a file or a std::string. All the modified data now can be security stored.

    READ: For read data you can use the read methods that are overloaded for many types of C++ data. Like:
        ---------------------------------------
            int variable;
            my_parser.read("age",variable);
        ---------------------------------------
        This example of code will read the value of key "age" as int and store it on "variable".
        The parser must already have parsed the file with the methods shown before.

        Take care! Is very recommended that you read and write data with consistent types.
            If you write data as float and read as int or other type you will be fucked by example.

        If the key isn't on the cache the variable will not be modified. This can be very powerfull as you can set default values.
            --------------------------------------
                bool flag = true;
                my_parser.read("active",flag);
            --------------------------------------

    WRITE: For write data use the write methods.
        ------------------------------------------
            float mass = 45.6f;
            my_parser.write("the-mass",mass);
        ------------------------------------------
            The data will be correctly writed as the write methods have overload for each type of c++ data.

        Bool data will be writed and read as yes/no so, if you write:
        ------------------------------------------
            bool test = false;
            my_parse.write("hes_gay",test);
        ------------------------------------------
            After write the data to file using the methods shown before, the file will be like:
            -------------------------------------
                hes_gay = no
            -------------------------------------

    ERASE: To erase a key from the parser cache use:
        ----------------------------------------
            my_parser.erase("key name");
        ----------------------------------------
            This is self explanatory

    CLEAR: To erase all data of the cache (clear) use:
        ----------------------------------------
            my_parser.clear();
        ----------------------------------------
            This is self explanatory

    EXAMPLE: Look a example on example.cpp and example.txt file!

    DEBUG: If DEBUG_MODE is defined at compilation time the parser will output the key => values parsed.

                                        Diego Pinto & Grégory Gusberti @ openGA project 2014/2
---------------------------------------------------------------------------------------------*/

#pragma once

#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>

/* Namespace that contains the parser.
    Only for organization purposes.
*/
namespace configParser {
    class Parser {
        private:
        std::unordered_map<std::string,std::string>data;

        void parse(std::string line);

        public:
            // METHODS FOR PARSE AND WRITE FILES
            // Numeric values will be written as numbers, boolean as yes/no and std::string as the actual string.

                // Parse the data from a string. The data need to be formated as in a normal .txt file with /n as break lines.
                void parseFromString(const std::string &data);

                // Writed the cached data to a string.
                void writeToString  (std::string &data);

                // Parse the data from a file. The parser will parse util a EOF is reach.
                // All the data will be mapped to memory as key => velue for future use.
                bool parseFromFile  (const std::string &file_name);

                // Write all the parsed and modified data to a file.
                // It can be a new file with diferent name of the same as used to get the data.
                // If the same file is used all the original comments and identation will be lost
                // as the parser will write each key => value in each line.
                bool writeToFile    (const std::string &file_name);

            //----------------------------------------------------------------------------------------------------------------

            // METHODS FOR READ KEYS
            // This are the methods for read data from the cached parsed file. If the key is not avalible on the
            // container the original data of the variable will no be modified.

                // Read a bool. The value of the key need to be at yes/no format.
                void read(std::string key, bool                 &value);

                // Read numeric values
                void read(std::string key, unsigned int         &value);
                void read(std::string key, int                  &value);
                void read(std::string key, long unsigned int    &value);
                void read(std::string key, long int             &value);
                void read(std::string key, float                &value);
                void read(std::string key, double               &value);

                // Read a string as it was written on the parsed file.
                void read(std::string key, std::string          &value);

            //---------------------------------------------------------------------------------------------------------------

            // METHODS FOR READ DATA
            // This are the methods that you can use for write paramenters on the configFile
            // The paramenter will be stored on cache and written to file only on writeToFile(...) or writeToString(...) call.

                // Writes a boolean. The 0 or 1 value will be written as yes/no
                void write(std::string key, bool                 value);

                // Writes a string. The string will be written as it is.
                void write(std::string key, const std::string   &value);

                /* Template for numeric values.
                 This templates will work will
                    unsigned int,
                    int,
                    long unsigned int,
                    long int,
                    float,
                    double

                 If you need to write other type as short int or char, you can cast for int or unsigned int
                 */
                template<class T>
                    void write(std::string key,T value);

                // Erase a key => value from the cache
                void erase(std::string key);

                // Erase all parsed keys. This can be used for reuse of the parser.
                void clear();
    };

};


