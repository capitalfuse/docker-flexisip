/*
Copyright (C) 2017 Belledonne Communications SARL

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef _LINPHONE_CONFIG_HH
#define _LINPHONE_CONFIG_HH

#include <list>
#include <string>
#include <cstdint>
#include "object.hh"




struct _LinphoneConfig;


namespace linphone {

	class Config;

	/**
	 * @brief The #Config object is used to manipulate a configuration file. 
	 *
	 * The format of the configuration file is a .ini like format:
	 * 
	 * 
	 * Example:  
	 */
	class Config: public Object {
	
		public:

			Config(void *ptr, bool takeRef=true);
			LINPHONECXX_PUBLIC _LinphoneConfig *cPtr() {return (_LinphoneConfig *)mPrivPtr;}

	
		public:
			
		
			/**
			 * @brief Returns the list of sections' names in the LinphoneConfig. 
			 *
			 * @return A list of char * objects. char *  a null terminated static array of
			 * strings 
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getSectionsNamesList();
			
			/**
			 * @brief Removes entries for key,value in a section. 
			 *
			 * @param key 
			 */
			LINPHONECXX_PUBLIC void cleanEntry(const std::string & section, const std::string & key);
			
			/**
			 * @brief Removes every pair of key,value in a section and remove the section. 
			 *
			 */
			LINPHONECXX_PUBLIC void cleanSection(const std::string & section);
			
			/**
			 * @brief Dumps the #linphone::Config as INI into a buffer. 
			 *
			 * @return The buffer that contains the config dump 
			 */
			LINPHONECXX_PUBLIC std::string dump() const;
			
			/**
			 * @brief Dumps the #linphone::Config as XML into a buffer. 
			 *
			 * @return The buffer that contains the XML dump 
			 */
			LINPHONECXX_PUBLIC std::string dumpAsXml() const;
			
			/**
			 * @brief Retrieves a configuration item as a boolean, given its section, key, and
			 * default value. 
			 *
			 * The default boolean value is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC bool getBool(const std::string & section, const std::string & key, bool defaultValue) const;
			
			/**
			 * @brief Retrieves a default configuration item as a float, given its section,
			 * key, and default value. 
			 *
			 * The default float value is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC float getDefaultFloat(const std::string & section, const std::string & key, float defaultValue) const;
			
			/**
			 * @brief Retrieves a default configuration item as an integer, given its section,
			 * key, and default value. 
			 *
			 * The default integer value is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC int getDefaultInt(const std::string & section, const std::string & key, int defaultValue) const;
			
			/**
			 * @brief Retrieves a default configuration item as a 64 bit integer, given its
			 * section, key, and default value. 
			 *
			 * The default integer value is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC int64_t getDefaultInt64(const std::string & section, const std::string & key, int64_t defaultValue) const;
			
			/**
			 * @brief Retrieves a default configuration item as a string, given its section,
			 * key, and default value. 
			 *
			 * The default value string is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC std::string getDefaultString(const std::string & section, const std::string & key, const std::string & defaultValue) const;
			
			/**
			 * @brief Retrieves a configuration item as a float, given its section, key, and
			 * default value. 
			 *
			 * The default float value is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC float getFloat(const std::string & section, const std::string & key, float defaultValue) const;
			
			/**
			 * @brief Retrieves a configuration item as an integer, given its section, key,
			 * and default value. 
			 *
			 * The default integer value is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC int getInt(const std::string & section, const std::string & key, int defaultValue) const;
			
			/**
			 * @brief Retrieves a configuration item as a 64 bit integer, given its section,
			 * key, and default value. 
			 *
			 * The default integer value is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC int64_t getInt64(const std::string & section, const std::string & key, int64_t defaultValue) const;
			
			/**
			 * @brief Retrieves the overwrite flag for a config item. 
			 *
			 */
			LINPHONECXX_PUBLIC bool getOverwriteFlagForEntry(const std::string & section, const std::string & key) const;
			
			/**
			 * @brief Retrieves the overwrite flag for a config section. 
			 *
			 */
			LINPHONECXX_PUBLIC bool getOverwriteFlagForSection(const std::string & section) const;
			
			/**
			 * @brief Retrieves a configuration item as a range, given its section, key, and
			 * default min and max values. 
			 *
			 * @return  if the value is successfully parsed as a range, true otherwise. If
			 * true is returned, min and max are filled respectively with default_min and
			 * default_max values. 
			 */
			LINPHONECXX_PUBLIC bool getRange(const std::string & section, const std::string & key, int * min, int * max, int defaultMin, int defaultMax) const;
			
			/**
			 * @brief Retrieves a section parameter item as a string, given its section and
			 * key. 
			 *
			 * The default value string is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC std::string getSectionParamString(const std::string & section, const std::string & key, const std::string & defaultValue) const;
			
			/**
			 * @brief Retrieves the skip flag for a config item. 
			 *
			 */
			LINPHONECXX_PUBLIC bool getSkipFlagForEntry(const std::string & section, const std::string & key) const;
			
			/**
			 * @brief Retrieves the skip flag for a config section. 
			 *
			 */
			LINPHONECXX_PUBLIC bool getSkipFlagForSection(const std::string & section) const;
			
			/**
			 * @brief Retrieves a configuration item as a string, given its section, key, and
			 * default value. 
			 *
			 * The default value string is returned if the config item isn't found. 
			 */
			LINPHONECXX_PUBLIC std::string getString(const std::string & section, const std::string & key, const std::string & defaultString) const;
			
			/**
			 * @brief Retrieves a configuration item as a list of strings, given its section,
			 * key, and default value. 
			 *
			 * The default value is returned if the config item is not found. 
			 * 
			 * @param defaultList A list of const char * objects. const char *  
			 * 
			 * @return A list of const char * objects. const char *  
			 */
			LINPHONECXX_PUBLIC std::list<std::string> getStringList(const std::string & section, const std::string & key, const std::list<std::string> & defaultList) const;
			
			/**
			 * @brief Returns 1 if a given section with a given key is present in the
			 * configuration. 
			 *
			 * @param key 
			 */
			LINPHONECXX_PUBLIC int hasEntry(const std::string & section, const std::string & key) const;
			
			/**
			 * @brief Returns 1 if a given section is present in the configuration. 
			 *
			 */
			LINPHONECXX_PUBLIC int hasSection(const std::string & section) const;
			
			/**
			 * @brief Reads a xml config file and fill the #linphone::Config with the read
			 * config dynamic values. 
			 *
			 * @param filename The filename of the config file to read to fill the
			 * #linphone::Config 
			 */
			LINPHONECXX_PUBLIC std::string loadFromXmlFile(const std::string & filename);
			
			/**
			 * @brief Reads a xml config string and fill the #linphone::Config with the read
			 * config dynamic values. 
			 *
			 * @param buffer The string of the config file to fill the #linphone::Config 
			 * 
			 * @return 0 in case of success 
			 */
			LINPHONECXX_PUBLIC linphone::Status loadFromXmlString(const std::string & buffer);
			
			/**
			 * @brief Reads a user config file and fill the #linphone::Config with the read
			 * config values. 
			 *
			 * @param filename The filename of the config file to read to fill the
			 * #linphone::Config 
			 */
			LINPHONECXX_PUBLIC linphone::Status readFile(const std::string & filename);
			
			/**
			 *
			 * @return  if file exists relative to the to the current location 
			 */
			LINPHONECXX_PUBLIC bool relativeFileExists(const std::string & filename) const;
			
			/**
			 * @brief Sets a boolean config item. 
			 *
			 */
			LINPHONECXX_PUBLIC void setBool(const std::string & section, const std::string & key, bool value);
			
			/**
			 * @brief Sets a float config item. 
			 *
			 */
			LINPHONECXX_PUBLIC void setFloat(const std::string & section, const std::string & key, float value);
			
			/**
			 * @brief Sets an integer config item. 
			 *
			 */
			LINPHONECXX_PUBLIC void setInt(const std::string & section, const std::string & key, int value);
			
			/**
			 * @brief Sets a 64 bits integer config item. 
			 *
			 */
			LINPHONECXX_PUBLIC void setInt64(const std::string & section, const std::string & key, int64_t value);
			
			/**
			 * @brief Sets an integer config item, but store it as hexadecimal. 
			 *
			 */
			LINPHONECXX_PUBLIC void setIntHex(const std::string & section, const std::string & key, int value);
			
			/**
			 * @brief Sets the overwrite flag for a config item (used when dumping config as
			 * xml) 
			 *
			 */
			LINPHONECXX_PUBLIC void setOverwriteFlagForEntry(const std::string & section, const std::string & key, bool value);
			
			/**
			 * @brief Sets the overwrite flag for a config section (used when dumping config
			 * as xml) 
			 *
			 */
			LINPHONECXX_PUBLIC void setOverwriteFlagForSection(const std::string & section, bool value);
			
			/**
			 * @brief Sets a range config item. 
			 *
			 */
			LINPHONECXX_PUBLIC void setRange(const std::string & section, const std::string & key, int minValue, int maxValue);
			
			/**
			 * @brief Sets the skip flag for a config item (used when dumping config as xml) 
			 *
			 */
			LINPHONECXX_PUBLIC void setSkipFlagForEntry(const std::string & section, const std::string & key, bool value);
			
			/**
			 * @brief Sets the skip flag for a config section (used when dumping config as
			 * xml) 
			 *
			 */
			LINPHONECXX_PUBLIC void setSkipFlagForSection(const std::string & section, bool value);
			
			/**
			 * @brief Sets a string config item. 
			 *
			 */
			LINPHONECXX_PUBLIC void setString(const std::string & section, const std::string & key, const std::string & value);
			
			/**
			 * @brief Sets a string list config item. 
			 *
			 * @param value A list of const char * objects. const char *  The value to set 
			 */
			LINPHONECXX_PUBLIC void setStringList(const std::string & section, const std::string & key, const std::list<std::string> & value);
			
			/**
			 * @brief Writes the config file to disk. 
			 *
			 */
			LINPHONECXX_PUBLIC linphone::Status sync();
			
			/**
			 * @brief Write a string in a file placed relatively with the Linphone
			 * configuration file. 
			 *
			 * @param data String to write 
			 */
			LINPHONECXX_PUBLIC void writeRelativeFile(const std::string & filename, const std::string & data) const;
			
			;
			/**
			 * @brief Instantiates a #linphone::Config object from a user provided buffer. 
			 *
			 * The caller of this constructor owns a reference. linphone_config_unref must be
			 * called when this object is no longer needed.
			 * 
			 * @param buffer the buffer from which the #linphone::Config will be retrieved. We
			 * expect the buffer to be null-terminated. 
			 * 
			 * @see linphone_config_new_with_factory 
			 * 
			 * @see linphone_config_new 
			 */
			LINPHONECXX_PUBLIC static std::shared_ptr<linphone::Config> newFromBuffer(const std::string & buffer);
			
;
			/**
			 * @brief Instantiates a #linphone::Config object from a user config file and a
			 * factory config file. 
			 *
			 * The caller of this constructor owns a reference. linphone_config_unref must be
			 * called when this object is no longer needed.
			 * 
			 * @param factoryConfigFilename the filename of the factory config file to read to
			 * fill the instantiated #linphone::Config 
			 * 
			 * @see linphone_config_new
			 * 
			 * The user config file is read first to fill the #linphone::Config and then the
			 * factory config file is read. Therefore the configuration parameters defined in
			 * the user config file will be overwritten by the parameters defined in the
			 * factory config file. 
			 */
			LINPHONECXX_PUBLIC static std::shared_ptr<linphone::Config> newWithFactory(const std::string & configFilename, const std::string & factoryConfigFilename);
			

	};

};

#endif // _LINPHONE_CONFIG_HH
