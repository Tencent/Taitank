#
# Be sure to run `pod lib lint hippy.podspec --verbose --use-libraries' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
    puts 'taitank.podspec read begins'
    s.name             = 'taitank'
    s.version          = '1.0.2'
    s.summary          = 'Taitank Cross Platform Layout'
  
  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  
    s.description      = <<-DESC
                          Taitank is a cross platform lightweight flex layout engine implemented in C++.
                         DESC
    s.homepage         = 'https://taitank.dev/'
    s.license          = { :type => 'Apache2', :file => 'LICENSE' }
    s.author           = 'OpenHippy Team'
    s.source           = {:git => 'https://github.com/Tencent/Taitank.git', :tag => s.version}
    s.platform = :ios
    s.ios.deployment_target = '10.0'
    s.source_files = 'src/*.{h,cc}'
    s.public_header_files = 'src/*.h'
    s.libraries = 'c++'
  
    puts 'hippy.podspec read ends'
  end
  