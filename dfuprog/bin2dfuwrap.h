#ifndef __BIN2FUWRAP_H__
#define __BIN2FUWRAP_H__

#include <string>


class Bin2DfuWrapper
{
public:
    //typedef unsigned char BOOL;
    //const unsigned char FALSE = 0;
    //const unsigned char TRUE = 1;

    Bin2DfuWrapper(unsigned long inAddress = 0x0000, bool inVerboseOn = false)
    {
        g_bVerbose = inVerboseOn;
        g_bQuiet = false;
        g_bOverwrite = true;
        g_bAdd = true;
        g_bCheck = false;
        g_bForce = false;
        g_ulAddress = inAddress;
        g_usVendorID = 0x1CBE;    // Texas Instruments (Tiva)
        g_usProductID = 0x00FF;    // DFU boot loader
        g_usDeviceID = 0x0000;

        g_pszOutput = "image.dfu";
    }

    ~Bin2DfuWrapper() {}

    int applyWrapper(const std::string& inSourceFilePath, const std::string& inDestFilePath);

private:
    unsigned long Reflect(unsigned long ulRef, char ucCh);
    void InitCRC32Table();
    unsigned long CalculateCRC32(unsigned char *pcData, unsigned long ulLength);
    unsigned char * ReadInputFile(const std::string& pcFilename, bool bHdrs, unsigned long *pulLength);
    bool IsPrefixValid(unsigned char *pcPrefix, unsigned char *pcEnd);
    bool IsSuffixValid(unsigned char *pcData, unsigned char *pcEnd);
    void DumpPrefix(unsigned char *pcPrefix);
    void DumpSuffix(unsigned char *pcEnd);
    int WriteOutputFile(const std::string& pszFile, unsigned char *pcData, unsigned long ulLength);


    //*****************************************************************************
    //
    // Globals controlled by various command line parameters.
    //
    //*****************************************************************************
    bool g_bVerbose;
    bool g_bQuiet;
    bool g_bOverwrite;
    bool g_bAdd;
    bool g_bCheck;
    bool g_bForce;
    unsigned long  g_ulAddress;
    unsigned short g_usVendorID;
    unsigned short g_usProductID;
    unsigned short g_usDeviceID;
    std::string g_pszOutput;

};

#endif // __BIN2FUWRAP_H__
