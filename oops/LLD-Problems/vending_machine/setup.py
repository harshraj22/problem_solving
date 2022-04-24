from os import path
from setuptools import setup

here = path.abspath(path.dirname(__file__))

# Get the long description from the README file
with open(path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='vending_machine',
    version='1.0.0',
    description='LLD problem of Vending Machine',
    long_description=long_description,
    packages=['src'],
    python_requires='>=3.8'
)
