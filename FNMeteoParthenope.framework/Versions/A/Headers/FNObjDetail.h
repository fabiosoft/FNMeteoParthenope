/** @class  FNObjDetail FNObjDetail.h
 *  @brief  Class object, describe complex information
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Class object, describe complex information based on a key identifier and a value. Subclass this if you need to associate more information to an object like FNForecastDetail
 *  @date   July 2013
 */


#import <Foundation/Foundation.h>
#import "NSObject+AutoCoding.h"

@interface FNObjDetail : NSObject <NSCoding>

/**
 The key identifier
 */
@property (nonatomic,strong) NSString *key;

/**
 The Value, could be aby object
 */
@property (nonatomic,strong) id value;


/**
 Initializer
 @param key identifies the value, like a unit measurement
 @param value the value associated
 @returns new FNObjDetail
 */
-(id)initWithKey:(NSString *)key value:(NSString *)value;


@end
