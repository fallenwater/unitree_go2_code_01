from setuptools import setup

from glob import glob
package_name = 'go2_driver_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + "/launch", glob("launch/*.launch.py")),  # 指定安装所有*.launch.py的文件
        ('share/' + package_name + "/rviz", glob("rviz/*.rviz")),           # 指定安装所有*.rviz.py的文件
        ('share/' + package_name + "/params", glob("params/*.yaml")),       # 指定安装所有*.yaml的文件
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='xn',
    maintainer_email='xn@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'driver_py = go2_driver_py.driver_py:main'
        ],
    },
)
