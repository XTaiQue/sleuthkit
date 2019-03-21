/*
** The Sleuth Kit
**
** Brian Carrier [carrier <at> sleuthkit [dot] org]
** Copyright (c) 2010-2019 Brian Carrier.  All Rights reserved
**
** This software is distributed under the Common Public License 1.0
**
*/

#include <shlwapi.h>
#include <string>
#include <algorithm>

#include "LogicalImagerSizeRule.h"

LogicalImagerSizeRule::LogicalImagerSizeRule(TSK_OFF_T min, TSK_OFF_T max) {
    m_min = min;
    m_max = max;
}

LogicalImagerSizeRule::~LogicalImagerSizeRule()
{
}

/**
* Is the file within the min and max size
*
* @param fs_file TSK_FS_FILE containing the filename
* @param path parent path to fs_file
* @returns true if extension is in the rule
*         false otherwise
*/
bool LogicalImagerSizeRule::matches(TSK_FS_FILE * fs_file, const char * path) const
{
    if (fs_file->meta == NULL)
        return false;

    if (m_max == 0) {
        // no upper limit, check the min size
        if (fs_file->meta->size >= m_min)
            return true;
        else
            return false;
    } else {
        if (fs_file->meta->size >= m_min && fs_file->meta->size <= m_max) {
            return true;
        } else {
            return false;
        }
    }
}
