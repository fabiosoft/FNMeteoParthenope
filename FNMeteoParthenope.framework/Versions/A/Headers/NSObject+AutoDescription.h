/** @category  NSObject(AutoDescription) NSObject+AutoDescription.h
 *  @brief  Helper category.
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Helper category  based on NSObject. If you need to subclass an FN class, this helps you to describe all ivars.
 *  @date   July 2013
 */
#import <Foundation/Foundation.h>

@interface NSObject(AutoDescription)

/**
 *  Reflects about self.
 *  Automatic description based on Reflection
 *  SuperClass' properties included (until NSObject).
 *  Can be in real description or somewhere else
 *  @param alsoNull if NO, ll null iVars will be excluded
 *  @returns Format: [ClassName {prop1 = val1; prop2 = val2; }]
 */
- (NSString *) autoDescriptionWithNULLIvars:(BOOL)alsoNull;

@end
