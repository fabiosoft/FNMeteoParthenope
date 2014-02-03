//
//  NSString+Helpers.h

//
//  Created by Reejo Samuel on 8/2/13.
//  Copyright (c) 2013 Reejo Samuel | m[at]reejosamuel.com All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Helpers)

-(NSString *)MD5;
-(NSString *)sha1;
-(NSString *)reverse;
-(NSString *)URLEncode;
-(NSString *)URLDecode;
-(NSString *)stringByStrippingWhitespace;
-(NSString *)substringFrom:(NSInteger)from to:(NSInteger)to;
-(NSString *)CapitalizeFirst;
-(NSString *)UnderscoresToCamelCase:(NSString*)underscores;
-(NSString *)CamelCaseToUnderscores:(NSString *)input;

-(NSUInteger)countWords;
-(NSString *)firstWord;
-(NSArray*)getAllWords;

-(BOOL)contains:(NSString *)string;
-(BOOL)isBlank;

-(NSDate *)generateDateWithFormat:(NSString *)format;
-(NSDate *)formatWithStyle:(NSDateFormatterStyle)style;

+(NSString *) applicationDocumentsDirectory;
@end
