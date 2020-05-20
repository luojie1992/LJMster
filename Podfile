source "https://github.com/CocoaPods/Specs.git"

# Uncomment this line to define a global platform for your project
platform :ios, '8.0'
# Uncomment this line if you're using Swift
#use_frameworks!

project 'LJMster.project'


# 去掉由pod引入的第三方库的警告，需要更新命令才生效
inhibit_all_warnings!

# pod 快速更新方法
# pod update --verbose --no-repo-update

target 'LJMster' do
    
    # BAHome 系列代码
    pod 'BANetManager'
    pod 'BAButton'
    pod 'BAAlert'
    pod 'BAPickView'
    pod 'BATouchID'
    pod 'BATextView'
#    pod 'BAAlertController'
    pod 'FLEX'

    # 对系统原生的AutoLayout 的 NSLayoutConstraints类的封装，优雅的链式语法，GitHub 排名第三
    pod 'Masonry'
    
    # 两个都是自动布局框架
    pod 'SDAutoLayout'
    
    
    # 为滚动控件（UIScrollView, UITableView, UICollectionView）添加头部脚部刷新UI
    pod 'MJRefresh'
    
    # 键盘框架
    pod 'IQKeyboardManager'
    
    # 专门用于转换 Array/Dictionary -> 对象模型 主要用于JSON解析，基本都用这个框架（必会）
    pod 'MJExtension'
    
    # GitHub 排名第一的网络操作框架，底层使用NSURLSession+NSOperation(多线程)
    pod 'AFNetworking'
    
    # 在屏幕中间显示 加载框 类似于安卓的toast效果
    pod 'MBProgressHUD'
    
    # 数据库 sqlite
    pod 'FMDB'

    # 网络或本地 多张图片浏览 控制器
#    pod 'MWPhotoBrowser'

    # 友盟分享
#    pod 'UMengSocial', '~> 4.4'
#    pod 'UMengSocialCOM', '~> 5.2.1'
        pod 'UMengUShare/UI'

        # 集成新浪微博 【友盟官网技术文档这里标点符号有错，导入的时候记得更改】
        pod 'UMengUShare/Social/Sina'
        # 集成微信
        pod 'UMengUShare/Social/WeChat'

        # 集成QQ
        pod 'UMengUShare/Social/QQ'
        # 集成支付宝
        pod 'UMengUShare/Social/AlipayShare'


    # 百度地图SDK
#    pod 'BaiduMapKit'

    # 二维码
    #pod 'LBXScan','~> 1.1.1'
#    pod 'LBXAlertAction'
#    pod 'ZXingObjC', '~> 3.0'

    # 离屏渲染，切边角
    pod 'JMRoundedCorner'
    pod 'AppTrace'

    
    # 把系统的target+selector/委托模式 转为 Block语法，让代码结构更加紧凑
#    pod 'BlocksKit'

    # Facebook kit 框架
#    pod 'AsyncDisplayKit'


    # 自定义提示框
#    pod 'Toast', '~> 3.0'

    # 线性布局MyLinearLayout/相对布局MyRelativeLayout/框架布局MyFrameLayout/表格布局MyTableLayout/流式布局MyFlowLayout/浮动布局MyFloatLayout/SizeClass的支持
    pod 'MyLayout'

    # 各种封装的集合！大神的多年积累！
#    pod 'YYKit'

    # 内存泄露检测工具
   # pod 'MLeaksFinder'
    
    # 空数据的处理
    pod 'NullSafe'
    
    # oc 与 js 交互框架
#    pod 'WebViewJavascriptBridge', '~> 5.0'

    # Facebook的内存检测工具
#    pod 'FBMemoryProfiler'

    # 空数据 的三方库
#    pod 'DZNEmptyDataSet'


    # 截屏
#    pod 'SDScreenshotCapture'


    
    # 类似QQ侧滑框架
#    pod "JVFloatingDrawer"

    # 获取所有设备型号
#    pod 'DeviceUtil'

    # 一个 UICollectionViewLayout，长按可以拖拽排序，同时支持纵向和横线滚动。
# pod 'LewReorderableLayout'
    
    # WebView的进度条
#    pod 'NJKWebViewProgress'
    
    # 一个支持多选、选原图和视频的图片选择器，同时有预览功能，适配了iOS6789系统。
#    pod 'TZImagePickerController'

    # 一款支持七牛云存储的ios/mac sdk。它基于AFNetworking 2.x版本和七牛官方API构建。支持批量上传的七牛上传sdk
#    pod "QiniuUpload"

#facebook 出品KVO 使用类
 # pod 'KVOController'
  
#facebook 出品KVO 使用类
 # pod 'CHTCollectionViewWaterfallLayout'
  
 # pod 'MagicalRecord' ,'2.4.0'


# UIWebView页面信息的离线缓存
#推荐一个比较好的第三方库RNCachingURLProtocol ，只需要在AppDelegate中加入下面方法即可。
#
#[NSURLProtocolregisterClass:[RNCachingURLProtocolclass]];
#
#地址:https://github.com/rnapier/RNCachingURLProtocol

    # Aspect库是对面向切面编程(Aspect Oriented Programming)的实现，里面封装了Runtime的方法，也封装了上文的Method Swizzling方法。因此我们也可以看到，Method Swizzling也是AOP编程的一种。Aspect的用途很广泛，这里不具体展开，想了解更多的可以看一下官方github的介绍，已经够详细了。
    # pod "Aspects"
    
    # 友盟统计
    pod 'UMengAnalytics-NO-IDFA'

    # ReactiveObjC包含RAC 2原来包含的全部代码
    pod 'ReactiveObjC'
    
  #  pod 'YYDebugDatabase', :git => 'https://github.com/y500/YYDebugDatabase.git', :configurations => ['Debug']
    pod 'DoraemonKit/Core', '~> 3.0.0', :configurations => ['Debug']
      pod 'DoraemonKit/WithLogger', '~> 3.0.0', :configurations => ['Debug']
      pod 'DoraemonKit/WithGPS', '~> 3.0.0', :configurations => ['Debug']
      pod 'DoraemonKit/WithLoad', '~> 3.0.0', :configurations => ['Debug']
      pod 'DoraemonKit/WithWeex', '~> 3.0.0', :configurations => ['Debug']
      pod 'DoraemonKit/WithDatabase', '~> 3.0.0', :configurations => ['Debug']
      pod 'DoraemonKit/WithMLeaksFinder', '3.0.0', :configurations => ['Debug']


end



