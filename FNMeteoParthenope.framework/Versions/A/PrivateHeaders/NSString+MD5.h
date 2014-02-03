/** @category  NSString(MD5) NSString+MD5.h
 *  @brief  String helper MD5 category.
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Helper category  based on NSString. Convert any string in MD5.
 *  @date   July 2013
 */

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>

@interface NSString(MD5)

/**
	Convert the sting in MD5
	@returns MD5 value
 */
- (NSString *) MD5Hash;


@end

