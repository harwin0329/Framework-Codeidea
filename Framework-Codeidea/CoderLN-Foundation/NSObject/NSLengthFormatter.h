/*
 * NSLengthFormatter.h
 *
 * Foundation (c) 2014-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, NSLengthFormatterUnit) {
    NSLengthFormatterUnitMillimeter = 8,
    NSLengthFormatterUnitCentimeter = 9,
    NSLengthFormatterUnitMeter = 11,
    NSLengthFormatterUnitKilometer = 14,
    NSLengthFormatterUnitInch = (5 << 8) + 1,
    NSLengthFormatterUnitFoot = (5 << 8) + 2,
    NSLengthFormatterUnitYard = (5 << 8) + 3,
    NSLengthFormatterUnitMile = (5 << 8) + 4,
} API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface NSLengthFormatter : NSFormatter {
@private
    void *_formatter;
    BOOL _isForPersonHeight;
    void *_reserved[2];
}
@property (null_resettable, copy) NSNumberFormatter *numberFormatter;    // default is NSNumberFormatter with NSNumberFormatterDecimalStyle
@property NSFormattingUnitStyle unitStyle;              // default is NSFormattingUnitStyleMedium

@property (getter = isForPersonHeightUse) BOOL forPersonHeightUse;  // default is NO; if it is set to YES, the number argument for -stringFromMeters: and -unitStringFromMeters: is considered as a person's height

// Format a combination of a number and an unit to a localized string.
- (NSString *)stringFromValue:(double)value unit:(NSLengthFormatterUnit)unit;

// Format a number in meters to a localized string with the locale-appropriate unit and an appropriate scale (e.g. 4.3m = 14.1ft in the US locale).
- (NSString *)stringFromMeters:(double)numberInMeters;

// Return a localized string of the given unit, and if the unit is singular or plural is based on the given number.
- (NSString *)unitStringFromValue:(double)value unit:(NSLengthFormatterUnit)unit;

// Return the locale-appropriate unit, the same unit used by -stringFromMeters:.
- (NSString *)unitStringFromMeters:(double)numberInMeters usedUnit:(nullable NSLengthFormatterUnit *)unitp;

// No parsing is supported. This method will return NO.
- (BOOL)getObjectValue:(out id _Nullable * _Nullable)obj forString:(NSString *)string errorDescription:(out NSString * _Nullable * _Nullable)error;
@end
NS_ASSUME_NONNULL_END

