/*
 * UIReferenceLibraryViewController.h 
 *
 * UIKit (c) 2011-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
#import <UIKit/UIViewController.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(5_0) __TVOS_PROHIBITED
@interface UIReferenceLibraryViewController : UIViewController {}

/*! Returns YES if any installed dictionary has a definition for the provided term.
 */
+ (BOOL)dictionaryHasDefinitionForTerm:(NSString *)term;

/*! Initializes an instance of a UIReferenceLibraryViewController with the term provided.
 */
- (instancetype)initWithTerm:(NSString *)term NS_DESIGNATED_INITIALIZER;
- (instancetype) initWithCoder:(nonnull NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER; // Declared solely for the sake of potential subclassers.

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

CoderLN_NOTE NS_ASSUME_NONNULL_END
