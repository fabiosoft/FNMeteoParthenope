/** @class  FNCache FNCache.h
 *  @brief  Simple chaching class
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details It stores the files in your Caches folder. The default expiration time is 1 hour, but you can modify that if you need.
 *  @date   July 2013
 */

#import <Foundation/Foundation.h>

/**
	Cache expiration time in seconds. Default is 1h so 3600s
	@param double time in seconds
 */
static NSTimeInterval const cacheTime =  (double)3600;


@interface FNCache : NSObject

/**
	Reset entire cache
 */
+ (void) resetCache;

/**
	Set an NSData for key that need to be cached
	@param data data to save
	@param key MD5Hash of url string
 */
+ (void) setObject:(NSData*)data forKey:(NSString*)key;

/**
	Get object in cache
	@param key MD5Hash of url string
	@returns object as data or nil if not exists any saved cache
 */
+ (id) objectForKey:(NSString*)key;


@end
